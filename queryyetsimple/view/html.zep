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
namespace Queryyetsimple\View;

use RuntimeException;
use InvalidArgumentException;
use Queryyetsimple\View\Aconnect;
use Queryyetsimple\View\Iconnect;

/**
 * html 模板处理类
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2016.11.18
 * @version 1.0
 */
class Html extends Aconnect implements Iconnect
{

	/**
	 * 视图分析器
	 *
	 * @var \queryyetsimple\view\iparser
	 */
	protected objParse;

	/**
	 * 解析 parse
	 *
	 * @var callable
	 */
	protected static calParseResolver;

	/**
	 * 配置
	 *
	 * @var array
	 */
	protected arrOption = [
		"development" : false,
		"controller_name" : "index",
		"action_name" : "index",
		"controlleraction_depr" : "_",
		"theme_name" : "default",
		"theme_path" : "",
		"theme_path_default" : "",
		"suffix" : ".html",
		"theme_cache_path" : "",
		"cache_children" : false
	];

	/**
	 * 加载视图文件
	 *
	 * @param string $sFile 视图文件地址
	 * @param boolean $bDisplay 是否显示
	 * @param string $strExt 后缀
	 * @param string $sTargetCache 主模板缓存路径
	 * @param string $sMd5 源文件地址 md5 标记
	 * @return string
	 */
	public function display(string sFile, boolean bDisplay = true, string strExt = "", string sTargetCache = "", string sMd5 = "")
	{
		var sCachePath, sTargetContent, sChildCache, sReturn, strVarKey, mixVarValue;

		// 加载视图文件
		let sFile = this->parseDisplayFile(sFile, strExt);

		// 变量赋值
		if ! empty this->arrVar {
			for strVarKey, mixVarValue in this->arrVar {
				let {strVarKey} = mixVarValue;
			}
		}

		let sCachePath = this->getCachePath(sFile); // 编译文件路径
		if this->isCacheExpired(sFile, sCachePath) { // 重新编译
			this->parser()->doCombile(sFile, sCachePath);
		}

		// 逐步将子模板缓存写入父模板至到最后
		if sTargetCache {
			if is_file(sFile) && is_file(sTargetCache) {
				// 源码
				let sTargetContent = file_get_contents(sTargetCache);
				let sChildCache = file_get_contents(sCachePath);

				// 替换
				let sTargetContent = preg_replace("/<!--<\#\#\#\#incl\*" . sMd5 . "\*ude\#\#\#\#>-->(.*?)<!--<\/\#\#\#\#incl\*" . sMd5 . "\*ude\#\#\#\#\/>-->/s", substr(sChildCache, strpos(sChildCache, PHP_EOL)), sTargetContent);
				file_put_contents(sTargetCache, sTargetContent);
			} else {
				throw new InvalidArgumentException(sprintf("Source %s and target cache %s is not a valid path", sFile, sTargetCache));
			}
		}

		// 返回类型
		if bDisplay === false {
			ob_start();
			require sCachePath;
			let sReturn = ob_get_contents();
			ob_end_clean();
			this->fixIe(sReturn);
			return sReturn;
		} else {
			require sCachePath;
		}
	}

	/**
	 * 设置 parse 解析回调
	 *
	 * @param callable $calParseResolver
	 * @return void
	 */
	public static function setParseResolver(calParseResolver)
	{
		let self::calParseResolver = calParseResolver;
	}

	/**
	 * 解析 parse
	 *
	 * @return \queryyetsimple\view\iparser
	 */
	public function resolverParse()
	{
		if ! self::calParseResolver {
			throw new RuntimeException("Theme not set parse resolver");
		}
		return call_user_func(self::calParseResolver);
	}

	/**
	 * 获取分析器
	 *
	 * @return \queryyetsimple\view\iparser
	 */
	public function parser()
	{
		if typeof this->objParse != "null" {
			return this->objParse;
		}

		let this->objParse = this->resolverParse();
		return this->objParse;
	}

	/**
	 * 获取编译路径
	 *
	 * @param string $sFile
	 * @return string
	 */
	protected function getCachePath(string sFile)
	{
		if ! this->getOption("theme_cache_path") {
			throw new RuntimeException("Theme cache path must be set");
		}

		// 统一斜线
		let sFile = str_replace("//", "/", str_replace("\\", "/", sFile));

		// 统一缓存文件
		let sFile = basename(sFile, "." . pathinfo(sFile, PATHINFO_EXTENSION)) . "." . md5(sFile) . ".php";

		// 返回真实路径
		return this->getOption("theme_cache_path") . "/" . sFile;
	}

	/**
	 * 判断缓存是否过期
	 *
	 * @param string $sFile
	 * @param string $sCachePath
	 * @return boolean
	 */
	protected function isCacheExpired(string sFile, string sCachePath)
	{
		// 开启调试
		if this->getOption("app_development") {
			return true;
		}

		// 缓存文件不存在过期
		if ! is_file(sCachePath) {
			return true;
		}

		// 编译过期时间为 <= 0 表示永不过期
		if this->getOption("cache_lifetime") <= 0 {
			return false;
		}

		// 缓存时间到期
		if filemtime(sCachePath) + intval(this->getOption("cache_lifetime")) < time() {
			return true;
		}

		// 文件有更新
		if filemtime(sFile) >= filemtime(sCachePath) {
			return true;
		}

		return false;
	}

	/**
	 * 修复 ie 显示问题
	 * 过滤编译文件子模板定位注释标签，防止在网页头部出现注释，导致 IE 浏览器不居中
	 *
	 * @param string $sContent
	 * @return string
	 */
	protected function fixIe(string sContent)
	{
		if this->getOption("cache_children") === true {
			let sContent = preg_replace("/<!--<\#\#\#\#incl\*(.*?)\*ude\#\#\#\#>-->/", "", sContent);
			let sContent = preg_replace("/<!--<\/\#\#\#\#incl\*(.*?)\*ude\#\#\#\#\/>-->/", "", sContent);
		}
		return sContent;
	}
}
