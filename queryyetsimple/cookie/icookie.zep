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
namespace Queryyetsimple\Cookie;

/**
 * icookie 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.06
 * @version 1.0
 */
interface Icookie
{

    /**
     * 设置 COOKIE
     *
     * @param string $sName
     * @param string $mixValue
     * @param array $arrOption
     * @return void
     */
    public function set(string sName, var mixValue = "", array arrOption = []);

    /**
     * 批量插入
     *
     * @param string|array $mixKey
     * @param mixed $mixValue
     * @param array $arrOption
     * @return void
     */
    public function put(var mixKey, var mixValue = null, array arrOption = []);

    /**
     * 数组插入数据
     *
     * @param string $strKey
     * @param mixed $mixValue
     * @param array $arrOption
     * @return void
     */
    public function push(string strKey, var mixValue, array arrOption = []);

    /**
     * 合并元素
     *
     * @param string $strKey
     * @param array $arrValue
     * @param array $arrOption
     * @return void
     */
    public function merge(string strKey, array arrValue, array arrOption = []);

    /**
     * 弹出元素
     *
     * @param string $strKey
     * @param mixed $mixValue
     * @param array $arrOption
     * @return void
     */
    public function pop(string strKey, array arrValue, array arrOption = []);

    /**
     * 数组插入键值对数据
     *
     * @param string $strKey
     * @param mixed $mixKey
     * @param mixed $mixValue
     * @param array $arrOption
     * @return void
     */
    public function arrays(string strKey, var mixKey, var mixValue = null, array arrOption = []);

    /**
     * 数组键值删除数据
     *
     * @param string $strKey
     * @param mixed $mixKey
     * @return void
     */
    public function arraysDelete(string strKey, var mixKey, array arrOption = []);

    /**
     * 获取 cookie
     *
     * @param string $sName
     * @param mixed $mixDefault
     * @param array $arrOption
     * @return mixed
     */
    public function get(string sName, var mixDefault = null, array arrOption = []);

    /**
     * 删除 cookie
     *
     * @param string $sName
     * @param array $arrOption
     * @return void
     */
    public function delete(string sName, array arrOption = []);

    /**
     * 清空 cookie
     *
     * @param boolean $bOnlyPrefix
     * @param array $arrOption
     * @return void
     */
    public function clear(boolean bOnlyPrefix = true, array arrOption = []);
}
