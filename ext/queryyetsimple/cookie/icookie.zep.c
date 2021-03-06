
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * icookie 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.06
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Cookie_Icookie) {

	ZEPHIR_REGISTER_INTERFACE(Queryyetsimple\\Cookie, Icookie, queryyetsimple, cookie_icookie, queryyetsimple_cookie_icookie_method_entry);

	return SUCCESS;

}

/**
 * 设置 COOKIE
 *
 * @param string $name
 * @param string $value
 * @param array $option
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Cookie_Icookie, set);

/**
 * 批量插入
 *
 * @param string|array $keys
 * @param mixed $value
 * @param array $option
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Cookie_Icookie, put);

/**
 * 数组插入数据
 *
 * @param string $key
 * @param mixed $value
 * @param array $option
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Cookie_Icookie, push);

/**
 * 合并元素
 *
 * @param string $key
 * @param array $value
 * @param array $option
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Cookie_Icookie, merge);

/**
 * 弹出元素
 *
 * @param string $key
 * @param mixed $value
 * @param array $option
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Cookie_Icookie, pop);

/**
 * 数组插入键值对数据
 *
 * @param string $key
 * @param mixed $keys
 * @param mixed $value
 * @param array $option
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Cookie_Icookie, arrays);

/**
 * 数组键值删除数据
 *
 * @param string $key
 * @param mixed $keys
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Cookie_Icookie, arraysDelete);

/**
 * 获取 cookie
 *
 * @param string $name
 * @param mixed $defaults
 * @param array $option
 * @return mixed
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Cookie_Icookie, get);

/**
 * 删除 cookie
 *
 * @param string $name
 * @param array $option
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Cookie_Icookie, delete);

/**
 * 清空 cookie
 *
 * @param boolean $deletePrefix
 * @param array $option
 * @return void
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Cookie_Icookie, clear);

