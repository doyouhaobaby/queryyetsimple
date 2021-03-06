/*
 * This file is part of the ************************ package.
 * ##########################################################
 * #   ____                          ______  _   _ ______   #
 * #  /     \       ___  _ __  _   _ | ___ \| | | || ___ \  #
 * # |   (  ||(_)| / _ \| '__|| | | || |_/ /| |_| || |_/ /  #
 * #  \____/ |___||  __/| |   | |_| ||  __/ |  _  ||  __/   #
 * #       \__   | \___ |_|    \__  || |    | | | || |      #
 * #     Query Yet Simple      __/  |\_|    |_| |_|\_|      #
 * #                          |___ /  Since 2010.10.03      #
 * ##########################################################
 *
 * The PHP Framework For Code Poem As Free As Wind. <Query Yet Simple>
 * (c) 2010-2018 http://queryphp.com All rights reserved.
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
namespace Queryyetsimple\Log;

use RuntimeException;
use Queryyetsimple\Log\Ilog;
use InvalidArgumentException;
use Queryyetsimple\Log\Iconnect;
use Queryyetsimple\Support\Ijson;
use Queryyetsimple\Support\Iarray;

/**
 * 日志仓储
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.07
 * @version 1.0
 */
class Log implements Ilog
{

    /**
     * 存储连接对象
     *
     * @var \queryyetsimple\log\iconnect
     */
    protected connect;

    /**
     * 当前记录的日志信息
     *
     * @var array
     */
    protected logs = [];

    /**
     * 日志过滤器
     *
     * @var callable
     */
    protected filter;

    /**
     * 日志处理器
     *
     * @var callable
     */
    protected processor;

    /**
     * 配置
     *
     * @var array
     */
    protected option = [
        "enabled" : true,
        "level" : [
            self::DEBUG,
            self::INFO,
            self::NOTICE,
            self::WARNING,
            self::ERROR,
            self::CRITICAL,
            self::ALERT,
            self::EMERGENCY,
            self::SQL
        ],
        "time_format" : "[Y-m-d H:i]"
    ];

    /**
     * 构造函数
     *
     * @param \queryyetsimple\log\iconnect $connect
     * @param array $option
     * @return void
     */
    public function __construct(<Iconnect> connect, array option = [])
    {
        let this->connect = connect;
        this->options(option);
    }

    /**
     * 记录 emergency 日志
     *
     * @param string $message
     * @param array $context
     * @param boolean $write
     * @return array
     */
    public function emergency(var message, array context = [], boolean write = false)
    {
    	var action;
    	let action = write ? "write" : "log";
        return this->{action}(self::EMERGENCY, message, context);
    }

    /**
     * 记录 alert 日志
     *
     * @param string $message
     * @param array $context
     * @param boolean $write
     * @return array
     */
    public function alert(var message, array context = [], boolean write = false)
    {
    	var action;
    	let action = write ? "write" : "log";
        return this->{action}(self::ALERT, message, context);
    }

    /**
     * 记录 critical 日志
     *
     * @param string $message
     * @param array $context
     * @param boolean $write
     * @return array
     */
    public function critical(var message, array context = [], boolean write = false)
    {
    	var action;
    	let action = write ? "write" : "log";
        return this->{action}(self::CRITICAL, message, context);
    }

    /**
     * 记录 error 日志
     *
     * @param string $message
     * @param array $context
     * @param boolean $write
     * @return array
     */
    public function error(var message, array context = [], boolean write = false)
    {
    	var action;
    	let action = write ? "write" : "log";
        return this->{action}(self::ERROR, message, context);
    }

    /**
     * 记录 warning 日志
     *
     * @param string $message
     * @param array $context
     * @param boolean $write
     * @return array
     */
    public function warning(var message, array context = [], boolean write = false)
    {
    	var action;
    	let action = write ? "write" : "log";
        return this->{action}(self::WARNING, message, context);
    }

    /**
     * 记录 notice 日志
     *
     * @param string $message
     * @param array $context
     * @param boolean $write
     * @return array
     */
    public function notice(var message, array context = [], boolean write = false)
    {
    	var action;
    	let action = write ? "write" : "log";
        return this->{action}(self::NOTICE, message, context);
    }

    /**
     * 记录 info 日志
     *
     * @param string $message
     * @param array $context
     * @param boolean $write
     * @return array
     */
    public function info(var message, array context = [], boolean write = false)
    {
    	var action;
    	let action = write ? "write" : "log";
        return this->{action}(self::INFO, message, context);
    }

    /**
     * 记录 debug 日志
     *
     * @param string $message
     * @param array $context
     * @param boolean $write
     * @return array
     */
    public function debug(var message, array context = [], boolean write = false)
    {
    	var action;
    	let action = write ? "write" : "log";
        return this->{action}(self::DEBUG, message, context);
    }

    /**
     * 记录日志
     *
     * @param string $level
     * @param mixed $message
     * @param array $context
     * @return array
     */
    public function log(string level, var message, array context = [])
    {
        var data;

        // 是否开启日志
        if ! this->getOption("enabled") {
            return;
        }

        // 只记录系统允许的日志级别
        if ! in_array(level, this->getOption("level")) {
            return;
        }

        let message = date(this->getOption("time_format")) . this->formatMessage(message);

        let data = [
            level,
            message,
            context
        ];

        // 执行过滤器
        if typeof this->filter != "null" && call_user_func_array(this->filter, data) === false {
            return;
        }

        // 记录到内存方便后期调用
        if ! isset this->logs[level] {
            let this->logs[level] = [];
        }
        let this->logs[level][] = data;

        return data;
    }

    /**
     * 记录错误消息并写入
     *
     * @param string $level 日志类型
     * @param string $message 应该被记录的错误信息
     * @param array $context
     * @return void
     */
    public function write(string level, string message, array context = [])
    {
        this->saveStore([
            this->log(level, message, context)
        ]);
    }

    /**
     * 保存日志信息
     *
     * @return void
     */
    public function save()
    {
        var data;

        if ! this->logs {
            return;
        }

        for data in this->logs {
            this->saveStore(data);
        }

        this->clear();
    }

    /**
     * 注册日志过滤器
     *
     * @param callable $filter
     * @return void
     */
    public function registerFilter(var filter)
    {
    	if ! is_callable(filter) {
    		throw new InvalidArgumentException("Filter must be callable.");
    	}
        let this->filter = filter;
    }

    /**
     * 注册日志处理器
     *
     * @param callable $processor
     * @return void
     */
    public function registerProcessor(var processor)
    {
    	if ! is_callable(processor) {
    		throw new InvalidArgumentException("Processor must be callable.");
    	}
        let this->processor = processor;
    }

    /**
     * 清理日志记录
     *
     * @param string $level
     * @return int
     */
    public function clear(string level = null)
    {
        var count;

        if level && isset this->logs[level] {
            let count = count(this->logs[level]);
            let this->logs[level] = [];
        } else {
            let count = count(this->logs);
            let this->logs = [];
        }

        return count;
    }

    /**
     * 获取日志记录
     *
     * @param string $level
     * @return array
     */
    public function get(string level = null)
    {
        if level && isset this->logs[level] {
            return this->logs[level];
        } else {
            return this->logs;
        }
    }

    /**
     * 获取日志记录数量
     *
     * @param string $level
     * @return int
     */
    public function count(string level = null)
    {
        if level && isset this->logs[level] {
            return count(this->logs[level]);
        } else {
            return count(this->logs);
        }
    }

    /**
     * 修改单个配置
     *
     * @param string $name
     * @param mixed $value
     * @return $this
     */
    public function option(string name, var value)
    {
        if ! is_string(name) {
            throw new InvalidArgumentException("Option set name must be a string.");
        }
        let this->option[name] = value;
        return this;
    }

    /**
     * 修改数组配置
     *
     * @param string $name
     * @param array $value
     * @return $this
     */
    public function optionArray(string name, array value)
    {
        return this->option(name, array_merge(this->getOption(name), value));
    }

    /**
     * 修改多个配置
     *
     * @param string $name
     * @param mixed $value
     * @return $this
     */
    public function options(array option = [])
    {
    	var name, value;

        if empty option {
            return this;
        }

        for name, value in option {
        	this->option(name, value);
        }

        return this;
    }

    /**
     * 获取单个配置
     *
     * @param string $name
     * @param mixed $defaults
     * @return mixed
     */
    public function getOption(string name, var defaults = null)
    {
        return isset(this->option[name]) ? this->option[name] : defaults;
    }

    /**
     * 获取所有配置
     *
     * @param array $option
     * @return mixed
     */
    public function getOptions(array option = [])
    {
    	if ! empty option {
    		return array_merge(this->option, option);
    	} else {
    		return this->option;
    	}
    }

    /**
     * 删除单个配置
     *
     * @param string $name
     * @return $this
     */
    public function deleteOption(string name)
    {
        if isset this->option[name] {
            unset(this->option[name]);
        }

        return this;
    }

    /**
     * 删除多个配置
     *
     * @param array $option
     * @return $this
     */
    public function deleteOptions(array option = [])
    {
    	var key;

        if ! empty option {
            return this;
        }

        for key in option {
        	this->deleteOption(key);
        }

        return this;
    }

    /**
     * 存储日志
     *
     * @param array $data
     * @return void
     */
    protected function saveStore(array data)
    {
        // 执行处理器
        if typeof this->processor != "null" {
            call_user_func_array(this->processor, data);
        }
        this->connect->save(data);
    }

    /**
     * 格式化日志消息
     *
     * @param mixed $message
     * @return mixed
     */
    protected function formatMessage(var message)
    {
        if typeof message == "array" {
            return var_export(message, true);
        } elseif typeof message == "object" && message instanceof Ijson {
            return message->toJson();
        } elseif typeof message == "object" && message instanceof Iarray {
            return var_export(message->toArray(), true);
        } elseif is_scalar(message) {
            return message;
        }
        
        throw new RuntimeException("Message is invalid.");
    }

    /**
     * call 
     *
     * @param string $method
     * @param array $args
     * @return mixed
     */
    public function __call(string method, array args)
    {
    	return call_user_func_array([this->connect, method], args);
    }
}
