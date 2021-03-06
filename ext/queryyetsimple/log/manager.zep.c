
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


/**
 * log 入口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.07
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Log_Manager) {

	ZEPHIR_REGISTER_CLASS_EX(Queryyetsimple\\Log, Manager, queryyetsimple, log_manager, queryyetsimple_support_manager_ce, queryyetsimple_log_manager_method_entry, 0);

	return SUCCESS;

}

/**
 * 取得配置命名空间
 *
 * @return string
 */
PHP_METHOD(Queryyetsimple_Log_Manager, getOptionNamespace) {

	zval *this_ptr = getThis();


	RETURN_STRING("log");

}

/**
 * 创建连接对象
 *
 * @param object $objConnect
 * @return object
 */
PHP_METHOD(Queryyetsimple_Log_Manager, createConnect) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *objConnect, objConnect_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&objConnect_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &objConnect);



	object_init_ex(return_value, queryyetsimple_log_log_ce);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoptioncommon", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 24, objConnect, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 创建 file 日志驱动
 *
 * @param array $arrOption
 * @return \queryyetsimple\log\file
 */
PHP_METHOD(Queryyetsimple_Log_Manager, makeConnectFile) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arrOption_param = NULL, _0, _1;
	zval arrOption;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrOption);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arrOption_param);

	if (!arrOption_param) {
		ZEPHIR_INIT_VAR(&arrOption);
		array_init(&arrOption);
	} else {
		zephir_get_arrval(&arrOption, arrOption_param);
	}


	object_init_ex(return_value, queryyetsimple_log_file_ce);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "file");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoption", NULL, 0, &_1, &arrOption);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 25, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 创建 monolog 日志驱动
 *
 * @param array $arrOption
 * @return \queryyetsimple\log\monolog
 */
PHP_METHOD(Queryyetsimple_Log_Manager, makeConnectMonolog) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arrOption_param = NULL, _0, _1;
	zval arrOption;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrOption);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &arrOption_param);

	if (!arrOption_param) {
		ZEPHIR_INIT_VAR(&arrOption);
		array_init(&arrOption);
	} else {
		zephir_get_arrval(&arrOption, arrOption_param);
	}


	object_init_ex(return_value, queryyetsimple_log_monolog_ce);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "monolog");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoption", NULL, 0, &_1, &arrOption);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 26, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

