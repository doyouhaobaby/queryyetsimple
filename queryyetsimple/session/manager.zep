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
namespace Queryyetsimple\Session;

use Queryyetsimple\Session\Redis;
use Queryyetsimple\Session\Session;
use Queryyetsimple\Session\Memcache;
use Queryyetsimple\Support\Manager as support_manager;

/**
 * manager 入口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.09
 * @version 1.0
 */
class Manager extends support_manager
{

    /**
     * 取得配置命名空间
     *
     * @return string
     */
    protected function getOptionNamespace()
    {
        return "session";
    }

    /**
     * 创建连接对象
     *
     * @param object $connect
     * @return object
     */
    protected function createConnect(var connect)
    {
        return new Session(connect, this->getOptionCommon());
    }

    /**
     * 创建 cookie 缓存
     *
     * @param array $options
     * @return null
     */
    protected function makeConnectCookie(array options = [])
    {
        return null;
    }

    /**
     * 创建 memcache 缓存
     *
     * @param array $options
     * @return \queryyetsimple\session\memcache
     */
    protected function makeConnectMemcache(array options = [])
    {
        return new Memcache(this->getOption("memcache", options));
    }

    /**
     * 创建 redis 缓存
     *
     * @param array $options
     * @return \queryyetsimple\session\redis
     */
    protected function makeConnectRedis(array options = [])
    {
        return new Redis(this->getOption("redis", options));
    }

    /**
     * 读取连接配置
     *
     * @param string $connect
     * @return array
     */
    protected function getOptionConnect(string connect)
    {
        return this->optionFilterNull(parent::getOptionConnect(connect));
    }
}
