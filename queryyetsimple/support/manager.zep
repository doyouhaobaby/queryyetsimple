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
namespace Queryyetsimple\Support;

use Exception;
use InvalidArgumentException;
use Queryyetsimple\Support\Icontainer;

/**
 * manager 入口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.07
 * @version 1.0
 */
abstract class Manager
{

	/**
	 * IOC Container
	 *
	 * @var \queryyetsimple\support\icontainer
	 */
	protected container;

	/**
	 * 连接对象
	 *
	 * @var object[]
	 */
	protected connects;

	/**
	 * 构造函数
	 *
	 * @param \queryyetsimple\support\icontainer $container
	 * @return void
	 */
	public function __construct(<Icontainer> container)
	{
		let this->container = container;
	}

	/**
	 * 返回 IOC 容器
	 *
	 * @return \queryyetsimple\support\icontainer
	 */
	public function container()
	{
		return this->container;
	}

	/**
	 * 连接 connect 并返回连接对象
	 *
	 * @param array|string|null $options
	 * @return object
	 */
	public function connect(var options = null)
	{
		var unique, driver, temp;

		let temp = this->parseOptionAndUnique(options);
		let options = array_shift(temp);
		let unique = array_shift(temp);

		if isset this->connects[unique] {
			return this->connects[unique];
		}

		let driver = isset options["driver"] ? options["driver"] : this->getDefaultDriver();

		let this->connects[unique] = this->makeConnect(driver, options);

		return this->connects[unique];
	}

	/**
	 * 重新连接
	 *
	 * @param array|string $options
	 * @return object
	 */
	public function reconnect(var options = [])
	{
		this->disconnect(options);
		return this->connect(options);
	}

	/**
	 * 删除连接
	 *
	 * @param array|string $options
	 * @return void
	 */
	public function disconnect(var options = [])
	{
		var unique, temp;

		let temp = this->parseOptionAndUnique(options);
		let options = array_shift(temp);
		let unique = array_shift(temp);

		if isset this->connects[unique] {
			unset this->connects[unique];
		}
	}

	/**
	 * 取回所有连接
	 *
	 * @return object[]
	 */
	public function getConnects()
	{
		return this->connects;
	}

	/**
	 * 返回默认驱动
	 *
	 * @return string
	 */
	public function getDefaultDriver()
	{
		var strDefault;
		let strDefault = this->getOptionName("default");
		return this->getOptionObject()->get(strDefault);
	}

	/**
	 * 设置默认驱动
	 *
	 * @param string $name
	 * @return void
	 */
	public function setDefaultDriver(string name)
	{
		var strDefault;
		let strDefault = this->getOptionName("default");
		this->getOptionObject()->set(strDefault, name);
	}

	/**
	 * 取得配置命名空间
	 *
	 * @return string
	 */
	abstract protected function getOptionNamespace();

	/**
	 * 创建连接对象
	 *
	 * @param object $connect
	 * @return object
	 */
	abstract protected function createConnect(var connect);

	/**
	 * 取得连接名字
	 *
	 * @param string $name
	 * @return string
	 */
	protected function getOptionName(string name = null)
	{
		return this->getOptionNamespace() . "\\" . name;
	}

	/**
	 * 创建连接
	 *
	 * @param string $connect
	 * @param array $options
	 * @return object
	 */
	protected function makeConnect(string connect, array options = [])
	{
		var strTemp;
		let strTemp = this->getOptionName("connect." . connect);
		if typeof this->getOptionObject()->get(strTemp) == "null" {
			throw new Exception(sprintf("Connect driver %s not exits", connect));
		}
		return this->createConnect(this->createConnectCommon(connect, options));
	}

	/**
	 * 创建连接对象公共入口
	 *
	 * @param string $connect
	 * @param array $options
	 * @return object
	 */
	protected function createConnectCommon(string connect, array options = [])
	{
		var connect;
		let connect = "makeConnect" . ucwords(connect);
		return this->{connect}(options);
	}

	/**
	 * 分析连接参数以及其唯一值
	 *
	 * @param array|string $options
	 * @return array
	 */
	protected function parseOptionAndUnique(var options = [])
	{
		var unique;

		let options = this->parseOptionParameter(options);
		let unique = this->getUnique(options);

		return [
			options,
			unique
		];
	}

	/**
	 * 分析连接参数
	 *
	 * @param array|string $options
	 * @return array
	 */
	protected function parseOptionParameter(var options = [])
	{
		if typeof options == "null" {
			return [];
		}

		if typeof options == "string" {
			let options = this->getOptionObject()->get(this->getOptionName("connect." . options));
		}

		if typeof options != "array" {
			let options = [];
		}

		return options;
	}

	/**
	 * 取得唯一值
	 *
	 * @param array $options
	 * @return string
	 */
	protected function getUnique(array options)
	{
		return md5(serialize(options));
	}

	/**
	 * 读取默认配置
	 *
	 * @param string $connect
	 * @param array $extendOption
	 * @return array
	 */
	protected function getOption(string connect, array! extendOption = [])
	{
		if typeof extendOption != "array" {
			let extendOption = [];
		}
		return array_merge(this->getOptionConnect(connect), this->getOptionCommon(), extendOption);
	}

	/**
	 * 读取连接全局配置
	 *
	 * @return array
	 */
	protected function getOptionCommon()
	{
		var options;
		let options = this->getOptionObject()->get(this->getOptionName());
		let options = this->filterOptionCommon(options);
		return options;
	}

	/**
	 * 过滤全局配置
	 *
	 * @param array $options
	 * @return array
	 */
	protected function filterOptionCommon(array options)
	{
		var item;
		for item in this->filterOptionCommonItem() {
			if isset options[item] {
				unset options[item];
			}
		}

		return options;
	}

	/**
	 * 过滤全局配置项
	 *
	 * @return array
	 */
	protected function filterOptionCommonItem()
	{
		return [
			"default",
			"connect"
		];
	}

	/**
	 * 读取连接配置
	 *
	 * @param string $connect
	 * @return array
	 */
	protected function getOptionConnect(string connect)
	{
		return this->getOptionObject()->get(this->getOptionName("connect." . connect));
	}

	/**
	 * 清除配置 null
	 *
	 * @param array $options
	 * @return array
	 */
	protected function optionFilterNull(array options)
	{
		return array_filter(options, function (value) {
			return typeof value !== "null";
		});
	}

	/**
	 * 返回配置对象
	 *
	 * @return \queryyetsimple\option\option
	 */
	protected function getOptionObject()
	{
		return this->container->make("option");
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
		return call_user_func_array([this->connect(), method], args);
	}
}
