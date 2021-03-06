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
namespace Queryyetsimple\I18n;

use InvalidArgumentException;
use Queryyetsimple\I18n\Ii18n;

/**
 * 国际化组件
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.06
 * @version 1.0
 */
class I18n implements Ii18n
{

    /**
     * 当前语言上下文
     *
     * @var string
     */
    protected i18n;

    /**
     * 语言数据
     *
     * @var array
     */
    protected text = [];

    /**
     * 构造函数
     *
     * @param string $i18n
     * @return void
     */
    public function __construct(string i18n)
    {
        let this->i18n =  i18n;
    }

    /**
     * 获取语言 text
     *
     * @return string
     */
    public function getText()
    {
 		var arr, i18n;

  		let arr = func_get_args(); 

        if empty arr[0] {
            return "";
        }
      
        let i18n = this->getI18n();
        if isset this->text[i18n][arr[0]] {
        	let arr[0] = this->text[i18n][arr[0]];
        }

        if count(arr) > 1 {
            let arr[0] = call_user_func_array("sprintf", arr);
        }
        
        return arr[0];
    }

    /**
     * 获取语言 text
     *
     * @return string
     */
    public function __()
    {
    	var arr;
    	let arr = func_get_args();
        return call_user_func_arrray([this, "getText"], arr);
    }

    /**
     * 添加语言包
     *
     * @param string $i18n 语言名字
     * @param array $data 语言包数据
     * @return void
     */
    public function addText(string i18n, array data = [])
    {
        if array_key_exists(i18n, this->text) {
            let this->text[i18n] = array_merge(this->text[i18n], data);
        } else {
            let this->text[i18n] = data;
        }
    }

    /**
     * 设置当前语言包上下文环境
     *
     * @param string $i18n
     * @return void
     */
    public function setI18n(string i18n)
    {
        let this->i18n = i18n;
    }

    /**
     * 获取当前语言包
     *
     * @return string
     */
    public function getI18n()
    {
        return this->i18n;
    }
}
