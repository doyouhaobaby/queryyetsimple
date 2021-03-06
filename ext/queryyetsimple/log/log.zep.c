
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/variables.h"


/**
 * 日志仓储
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.07
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Log_Log) {

	ZEPHIR_REGISTER_CLASS(Queryyetsimple\\Log, Log, queryyetsimple, log_log, queryyetsimple_log_log_method_entry, 0);

	/**
	 * 存储连接对象
	 *
	 * @var \queryyetsimple\log\iconnect
	 */
	zend_declare_property_null(queryyetsimple_log_log_ce, SL("oConnect"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 当前记录的日志信息
	 *
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_log_log_ce, SL("arrLog"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 日志过滤器
	 *
	 * @var callable
	 */
	zend_declare_property_null(queryyetsimple_log_log_ce, SL("calFilter"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 日志处理器
	 *
	 * @var callable
	 */
	zend_declare_property_null(queryyetsimple_log_log_ce, SL("calProcessor"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * 配置
	 *
	 * @var array
	 */
	zend_declare_property_null(queryyetsimple_log_log_ce, SL("option"), ZEND_ACC_PROTECTED TSRMLS_CC);

	queryyetsimple_log_log_ce->create_object = zephir_init_properties_Queryyetsimple_Log_Log;

	zend_class_implements(queryyetsimple_log_log_ce TSRMLS_CC, 1, queryyetsimple_log_ilog_ce);
	return SUCCESS;

}

/**
 * 构造函数
 *
 * @param \queryyetsimple\log\iconnect $oConnect
 * @param array $option
 * @return void
 */
PHP_METHOD(Queryyetsimple_Log_Log, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval option;
	zval *oConnect, oConnect_sub, *option_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&oConnect_sub);
	ZVAL_UNDEF(&option);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &oConnect, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	zephir_update_property_zval(this_ptr, SL("oConnect"), oConnect);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "options", NULL, 0, &option);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 记录 emergency 日志
 *
 * @param string $mixMessage
 * @param array $arrContext
 * @param boolean $booWrite
 * @return array
 */
PHP_METHOD(Queryyetsimple_Log_Log, emergency) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool booWrite;
	zval arrContext;
	zval *mixMessage, mixMessage_sub, *arrContext_param = NULL, *booWrite_param = NULL, strAction, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mixMessage_sub);
	ZVAL_UNDEF(&strAction);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&arrContext);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &mixMessage, &arrContext_param, &booWrite_param);

	if (!arrContext_param) {
		ZEPHIR_INIT_VAR(&arrContext);
		array_init(&arrContext);
	} else {
		zephir_get_arrval(&arrContext, arrContext_param);
	}
	if (!booWrite_param) {
		booWrite = 0;
	} else {
		booWrite = zephir_get_boolval(booWrite_param);
	}


	if (booWrite) {
		ZEPHIR_INIT_VAR(&strAction);
		ZVAL_STRING(&strAction, "write");
	} else {
		ZEPHIR_INIT_NVAR(&strAction);
		ZVAL_STRING(&strAction, "log");
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "emergency");
	ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, &strAction, NULL, 0, &_0, mixMessage, &arrContext);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 记录 alert 日志
 *
 * @param string $mixMessage
 * @param array $arrContext
 * @param boolean $booWrite
 * @return array
 */
PHP_METHOD(Queryyetsimple_Log_Log, alert) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool booWrite;
	zval arrContext;
	zval *mixMessage, mixMessage_sub, *arrContext_param = NULL, *booWrite_param = NULL, strAction, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mixMessage_sub);
	ZVAL_UNDEF(&strAction);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&arrContext);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &mixMessage, &arrContext_param, &booWrite_param);

	if (!arrContext_param) {
		ZEPHIR_INIT_VAR(&arrContext);
		array_init(&arrContext);
	} else {
		zephir_get_arrval(&arrContext, arrContext_param);
	}
	if (!booWrite_param) {
		booWrite = 0;
	} else {
		booWrite = zephir_get_boolval(booWrite_param);
	}


	if (booWrite) {
		ZEPHIR_INIT_VAR(&strAction);
		ZVAL_STRING(&strAction, "write");
	} else {
		ZEPHIR_INIT_NVAR(&strAction);
		ZVAL_STRING(&strAction, "log");
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "alert");
	ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, &strAction, NULL, 0, &_0, mixMessage, &arrContext);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 记录 critical 日志
 *
 * @param string $mixMessage
 * @param array $arrContext
 * @param boolean $booWrite
 * @return array
 */
PHP_METHOD(Queryyetsimple_Log_Log, critical) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool booWrite;
	zval arrContext;
	zval *mixMessage, mixMessage_sub, *arrContext_param = NULL, *booWrite_param = NULL, strAction, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mixMessage_sub);
	ZVAL_UNDEF(&strAction);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&arrContext);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &mixMessage, &arrContext_param, &booWrite_param);

	if (!arrContext_param) {
		ZEPHIR_INIT_VAR(&arrContext);
		array_init(&arrContext);
	} else {
		zephir_get_arrval(&arrContext, arrContext_param);
	}
	if (!booWrite_param) {
		booWrite = 0;
	} else {
		booWrite = zephir_get_boolval(booWrite_param);
	}


	if (booWrite) {
		ZEPHIR_INIT_VAR(&strAction);
		ZVAL_STRING(&strAction, "write");
	} else {
		ZEPHIR_INIT_NVAR(&strAction);
		ZVAL_STRING(&strAction, "log");
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "critical");
	ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, &strAction, NULL, 0, &_0, mixMessage, &arrContext);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 记录 error 日志
 *
 * @param string $mixMessage
 * @param array $arrContext
 * @param boolean $booWrite
 * @return array
 */
PHP_METHOD(Queryyetsimple_Log_Log, error) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool booWrite;
	zval arrContext;
	zval *mixMessage, mixMessage_sub, *arrContext_param = NULL, *booWrite_param = NULL, strAction, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mixMessage_sub);
	ZVAL_UNDEF(&strAction);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&arrContext);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &mixMessage, &arrContext_param, &booWrite_param);

	if (!arrContext_param) {
		ZEPHIR_INIT_VAR(&arrContext);
		array_init(&arrContext);
	} else {
		zephir_get_arrval(&arrContext, arrContext_param);
	}
	if (!booWrite_param) {
		booWrite = 0;
	} else {
		booWrite = zephir_get_boolval(booWrite_param);
	}


	if (booWrite) {
		ZEPHIR_INIT_VAR(&strAction);
		ZVAL_STRING(&strAction, "write");
	} else {
		ZEPHIR_INIT_NVAR(&strAction);
		ZVAL_STRING(&strAction, "log");
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "error");
	ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, &strAction, NULL, 0, &_0, mixMessage, &arrContext);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 记录 warning 日志
 *
 * @param string $mixMessage
 * @param array $arrContext
 * @param boolean $booWrite
 * @return array
 */
PHP_METHOD(Queryyetsimple_Log_Log, warning) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool booWrite;
	zval arrContext;
	zval *mixMessage, mixMessage_sub, *arrContext_param = NULL, *booWrite_param = NULL, strAction, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mixMessage_sub);
	ZVAL_UNDEF(&strAction);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&arrContext);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &mixMessage, &arrContext_param, &booWrite_param);

	if (!arrContext_param) {
		ZEPHIR_INIT_VAR(&arrContext);
		array_init(&arrContext);
	} else {
		zephir_get_arrval(&arrContext, arrContext_param);
	}
	if (!booWrite_param) {
		booWrite = 0;
	} else {
		booWrite = zephir_get_boolval(booWrite_param);
	}


	if (booWrite) {
		ZEPHIR_INIT_VAR(&strAction);
		ZVAL_STRING(&strAction, "write");
	} else {
		ZEPHIR_INIT_NVAR(&strAction);
		ZVAL_STRING(&strAction, "log");
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "warning");
	ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, &strAction, NULL, 0, &_0, mixMessage, &arrContext);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 记录 notice 日志
 *
 * @param string $mixMessage
 * @param array $arrContext
 * @param boolean $booWrite
 * @return array
 */
PHP_METHOD(Queryyetsimple_Log_Log, notice) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool booWrite;
	zval arrContext;
	zval *mixMessage, mixMessage_sub, *arrContext_param = NULL, *booWrite_param = NULL, strAction, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mixMessage_sub);
	ZVAL_UNDEF(&strAction);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&arrContext);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &mixMessage, &arrContext_param, &booWrite_param);

	if (!arrContext_param) {
		ZEPHIR_INIT_VAR(&arrContext);
		array_init(&arrContext);
	} else {
		zephir_get_arrval(&arrContext, arrContext_param);
	}
	if (!booWrite_param) {
		booWrite = 0;
	} else {
		booWrite = zephir_get_boolval(booWrite_param);
	}


	if (booWrite) {
		ZEPHIR_INIT_VAR(&strAction);
		ZVAL_STRING(&strAction, "write");
	} else {
		ZEPHIR_INIT_NVAR(&strAction);
		ZVAL_STRING(&strAction, "log");
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "notice");
	ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, &strAction, NULL, 0, &_0, mixMessage, &arrContext);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 记录 info 日志
 *
 * @param string $mixMessage
 * @param array $arrContext
 * @param boolean $booWrite
 * @return array
 */
PHP_METHOD(Queryyetsimple_Log_Log, info) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool booWrite;
	zval arrContext;
	zval *mixMessage, mixMessage_sub, *arrContext_param = NULL, *booWrite_param = NULL, strAction, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mixMessage_sub);
	ZVAL_UNDEF(&strAction);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&arrContext);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &mixMessage, &arrContext_param, &booWrite_param);

	if (!arrContext_param) {
		ZEPHIR_INIT_VAR(&arrContext);
		array_init(&arrContext);
	} else {
		zephir_get_arrval(&arrContext, arrContext_param);
	}
	if (!booWrite_param) {
		booWrite = 0;
	} else {
		booWrite = zephir_get_boolval(booWrite_param);
	}


	if (booWrite) {
		ZEPHIR_INIT_VAR(&strAction);
		ZVAL_STRING(&strAction, "write");
	} else {
		ZEPHIR_INIT_NVAR(&strAction);
		ZVAL_STRING(&strAction, "log");
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "info");
	ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, &strAction, NULL, 0, &_0, mixMessage, &arrContext);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 记录 debug 日志
 *
 * @param string $mixMessage
 * @param array $arrContext
 * @param boolean $booWrite
 * @return array
 */
PHP_METHOD(Queryyetsimple_Log_Log, debug) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool booWrite;
	zval arrContext;
	zval *mixMessage, mixMessage_sub, *arrContext_param = NULL, *booWrite_param = NULL, strAction, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mixMessage_sub);
	ZVAL_UNDEF(&strAction);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&arrContext);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &mixMessage, &arrContext_param, &booWrite_param);

	if (!arrContext_param) {
		ZEPHIR_INIT_VAR(&arrContext);
		array_init(&arrContext);
	} else {
		zephir_get_arrval(&arrContext, arrContext_param);
	}
	if (!booWrite_param) {
		booWrite = 0;
	} else {
		booWrite = zephir_get_boolval(booWrite_param);
	}


	if (booWrite) {
		ZEPHIR_INIT_VAR(&strAction);
		ZVAL_STRING(&strAction, "write");
	} else {
		ZEPHIR_INIT_NVAR(&strAction);
		ZVAL_STRING(&strAction, "log");
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "debug");
	ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, &strAction, NULL, 0, &_0, mixMessage, &arrContext);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 记录日志
 *
 * @param string $strLevel
 * @param mixed $mixMessage
 * @param array $arrContext
 * @return array
 */
PHP_METHOD(Queryyetsimple_Log_Log, log) {

	zend_bool _9;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arrContext;
	zval *strLevel_param = NULL, *mixMessage = NULL, mixMessage_sub, *arrContext_param = NULL, arrData, _0, _1, _3, _4, _5, _6, _7, _8, _10, _11, _12$$6;
	zval strLevel;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strLevel);
	ZVAL_UNDEF(&mixMessage_sub);
	ZVAL_UNDEF(&arrData);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&arrContext);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &strLevel_param, &mixMessage, &arrContext_param);

	zephir_get_strval(&strLevel, strLevel_param);
	ZEPHIR_SEPARATE_PARAM(mixMessage);
	if (!arrContext_param) {
		ZEPHIR_INIT_VAR(&arrContext);
		array_init(&arrContext);
	} else {
		zephir_get_arrval(&arrContext, arrContext_param);
	}


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "enabled");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getoption", &_2, 0, &_1);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "level");
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getoption", &_2, 0, &_1);
	zephir_check_call_status();
	if (!(zephir_fast_in_array(&strLevel, &_3 TSRMLS_CC))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "time_format");
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getoption", &_2, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_5, "date", NULL, 15, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "formatmessage", NULL, 0, mixMessage);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_CONCAT_VV(&_7, &_5, &_6);
	ZEPHIR_CPY_WRT(mixMessage, &_7);
	ZEPHIR_INIT_VAR(&arrData);
	zephir_create_array(&arrData, 3, 0 TSRMLS_CC);
	zephir_array_fast_append(&arrData, &strLevel);
	zephir_array_fast_append(&arrData, mixMessage);
	zephir_array_fast_append(&arrData, &arrContext);
	ZEPHIR_OBS_VAR(&_8);
	zephir_read_property(&_8, this_ptr, SL("calFilter"), PH_NOISY_CC);
	_9 = Z_TYPE_P(&_8) != IS_NULL;
	if (_9) {
		ZEPHIR_INIT_NVAR(&_1);
		zephir_read_property(&_10, this_ptr, SL("calFilter"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_USER_FUNC_ARRAY(&_1, &_10, &arrData);
		zephir_check_call_status();
		_9 = ZEPHIR_IS_FALSE_IDENTICAL(&_1);
	}
	if (_9) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_11, this_ptr, SL("arrLog"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_11, &strLevel))) {
		ZEPHIR_INIT_VAR(&_12$$6);
		array_init(&_12$$6);
		zephir_update_property_array(this_ptr, SL("arrLog"), &strLevel, &_12$$6 TSRMLS_CC);
	}
	zephir_update_property_array_multi(this_ptr, SL("arrLog"), &arrData TSRMLS_CC, SL("za"), 2, &strLevel);
	RETURN_CCTOR(&arrData);

}

/**
 * 记录错误消息并写入
 *
 * @param string $strLevel 日志类型
 * @param string $strMessage 应该被记录的错误信息
 * @param array $arrContext
 * @return void
 */
PHP_METHOD(Queryyetsimple_Log_Log, write) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arrContext, _0;
	zval *strLevel_param = NULL, *strMessage_param = NULL, *arrContext_param = NULL, _1;
	zval strLevel, strMessage;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strLevel);
	ZVAL_UNDEF(&strMessage);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&arrContext);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &strLevel_param, &strMessage_param, &arrContext_param);

	zephir_get_strval(&strLevel, strLevel_param);
	zephir_get_strval(&strMessage, strMessage_param);
	if (!arrContext_param) {
		ZEPHIR_INIT_VAR(&arrContext);
		array_init(&arrContext);
	} else {
		zephir_get_arrval(&arrContext, arrContext_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "log", NULL, 0, &strLevel, &strMessage, &arrContext);
	zephir_check_call_status();
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "savestore", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 保存日志信息
 *
 * @return void
 */
PHP_METHOD(Queryyetsimple_Log_Log, save) {

	zval arrData, _0, _1, *_2;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrData);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("arrLog"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_1, this_ptr, SL("arrLog"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_1, 0, "queryyetsimple/log/log.zep", 297);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1), _2)
	{
		ZEPHIR_INIT_NVAR(&arrData);
		ZVAL_COPY(&arrData, _2);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "savestore", &_3, 0, &arrData);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&arrData);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "clear", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 注册日志过滤器
 *
 * @param callable $calFilter
 * @return void
 */
PHP_METHOD(Queryyetsimple_Log_Log, registerFilter) {

	zval *calFilter, calFilter_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&calFilter_sub);

	zephir_fetch_params(0, 1, 0, &calFilter);



	if (!(zephir_is_callable(calFilter TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Filter must be callable.", "queryyetsimple/log/log.zep", 309);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("calFilter"), calFilter);

}

/**
 * 注册日志处理器
 *
 * @param callable $calProcessor
 * @return void
 */
PHP_METHOD(Queryyetsimple_Log_Log, registerProcessor) {

	zval *calProcessor, calProcessor_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&calProcessor_sub);

	zephir_fetch_params(0, 1, 0, &calProcessor);



	if (!(zephir_is_callable(calProcessor TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(spl_ce_InvalidArgumentException, "Processor must be callable.", "queryyetsimple/log/log.zep", 323);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("calProcessor"), calProcessor);

}

/**
 * 清理日志记录
 *
 * @param string $strLevel
 * @return int
 */
PHP_METHOD(Queryyetsimple_Log_Log, clear) {

	zend_bool _0;
	zval *strLevel_param = NULL, nCount, _1, _2$$3, _3$$3, _4$$3, _5$$4, _6$$4;
	zval strLevel;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strLevel);
	ZVAL_UNDEF(&nCount);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &strLevel_param);

	if (!strLevel_param) {
		ZEPHIR_INIT_VAR(&strLevel);
		ZVAL_STRING(&strLevel, "");
	} else {
		zephir_get_strval(&strLevel, strLevel_param);
	}


	_0 = zephir_is_true(&strLevel);
	if (_0) {
		zephir_read_property(&_1, this_ptr, SL("arrLog"), PH_NOISY_CC | PH_READONLY);
		_0 = zephir_array_isset(&_1, &strLevel);
	}
	if (_0) {
		zephir_read_property(&_2$$3, this_ptr, SL("arrLog"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3$$3, &_2$$3, &strLevel, PH_NOISY | PH_READONLY, "queryyetsimple/log/log.zep", 339 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&nCount);
		ZVAL_LONG(&nCount, zephir_fast_count_int(&_3$$3 TSRMLS_CC));
		ZEPHIR_INIT_VAR(&_4$$3);
		array_init(&_4$$3);
		zephir_update_property_array(this_ptr, SL("arrLog"), &strLevel, &_4$$3 TSRMLS_CC);
	} else {
		zephir_read_property(&_5$$4, this_ptr, SL("arrLog"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&nCount);
		ZVAL_LONG(&nCount, zephir_fast_count_int(&_5$$4 TSRMLS_CC));
		ZEPHIR_INIT_VAR(&_6$$4);
		array_init(&_6$$4);
		zephir_update_property_zval(this_ptr, SL("arrLog"), &_6$$4);
	}
	RETURN_CCTOR(&nCount);

}

/**
 * 获取日志记录
 *
 * @param string $strLevel
 * @return array
 */
PHP_METHOD(Queryyetsimple_Log_Log, get) {

	zend_bool _0;
	zval *strLevel_param = NULL, _1, _2$$3, _3$$3;
	zval strLevel;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strLevel);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &strLevel_param);

	if (!strLevel_param) {
		ZEPHIR_INIT_VAR(&strLevel);
		ZVAL_STRING(&strLevel, "");
	} else {
		zephir_get_strval(&strLevel, strLevel_param);
	}


	_0 = zephir_is_true(&strLevel);
	if (_0) {
		zephir_read_property(&_1, this_ptr, SL("arrLog"), PH_NOISY_CC | PH_READONLY);
		_0 = zephir_array_isset(&_1, &strLevel);
	}
	if (_0) {
		zephir_read_property(&_2$$3, this_ptr, SL("arrLog"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3$$3, &_2$$3, &strLevel, PH_NOISY | PH_READONLY, "queryyetsimple/log/log.zep", 358 TSRMLS_CC);
		RETURN_CTOR(&_3$$3);
	} else {
		RETURN_MM_MEMBER(getThis(), "arrLog");
	}

}

/**
 * 获取日志记录数量
 *
 * @param string $strLevel
 * @return int
 */
PHP_METHOD(Queryyetsimple_Log_Log, count) {

	zend_bool _0;
	zval *strLevel_param = NULL, _1, _2$$3, _3$$3, _4$$4;
	zval strLevel;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strLevel);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &strLevel_param);

	if (!strLevel_param) {
		ZEPHIR_INIT_VAR(&strLevel);
		ZVAL_STRING(&strLevel, "");
	} else {
		zephir_get_strval(&strLevel, strLevel_param);
	}


	_0 = zephir_is_true(&strLevel);
	if (_0) {
		zephir_read_property(&_1, this_ptr, SL("arrLog"), PH_NOISY_CC | PH_READONLY);
		_0 = zephir_array_isset(&_1, &strLevel);
	}
	if (_0) {
		zephir_read_property(&_2$$3, this_ptr, SL("arrLog"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3$$3, &_2$$3, &strLevel, PH_NOISY | PH_READONLY, "queryyetsimple/log/log.zep", 373 TSRMLS_CC);
		RETURN_MM_LONG(zephir_fast_count_int(&_3$$3 TSRMLS_CC));
	} else {
		zephir_read_property(&_4$$4, this_ptr, SL("arrLog"), PH_NOISY_CC | PH_READONLY);
		RETURN_MM_LONG(zephir_fast_count_int(&_4$$4 TSRMLS_CC));
	}

}

/**
 * 修改单个配置
 *
 * @param string $name
 * @param mixed $value
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Log_Log, option) {

	zval *name_param = NULL, *value, value_sub;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value);

	zephir_get_strval(&name, name_param);


	if (!(Z_TYPE_P(&name) == IS_STRING)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Option set name must be a string.", "queryyetsimple/log/log.zep", 389);
		return;
	}
	zephir_update_property_array(this_ptr, SL("option"), &name, value TSRMLS_CC);
	RETURN_THIS();

}

/**
 * 修改数组配置
 *
 * @param string $name
 * @param array $value
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Log_Log, optionArray) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval value;
	zval *name_param = NULL, *value_param = NULL, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &value_param);

	zephir_get_strval(&name, name_param);
	zephir_get_arrval(&value, value_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getoption", NULL, 0, &name);
	zephir_check_call_status();
	zephir_fast_array_merge(&_0, &_1, &value TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "option", NULL, 0, &name, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * 修改多个配置
 *
 * @param string $name
 * @param mixed $value
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Log_Log, options) {

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *option_param = NULL, name, value, *_0;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	if (ZEPHIR_IS_EMPTY(&option)) {
		RETURN_THIS();
	}
	zephir_is_iterable(&option, 0, "queryyetsimple/log/log.zep", 426);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&option), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&name, _2);
		} else {
			ZVAL_LONG(&name, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "option", &_3, 0, &name, &value);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_THIS();

}

/**
 * 获取单个配置
 *
 * @param string $name
 * @param mixed $defaults
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Log_Log, getOption) {

	zval *name_param = NULL, *defaults = NULL, defaults_sub, __$null, _0, _1, _2;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&defaults_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &defaults);

	zephir_get_strval(&name, name_param);
	if (!defaults) {
		defaults = &defaults_sub;
		defaults = &__$null;
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, &name)) {
		zephir_read_property(&_2, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_0, &_2, &name, PH_NOISY, "queryyetsimple/log/log.zep", 438 TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&_0, defaults);
	}
	RETURN_CCTOR(&_0);

}

/**
 * 获取所有配置
 *
 * @param array $option
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Log_Log, getOptions) {

	zval *option_param = NULL, _0$$3;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	if (!(ZEPHIR_IS_EMPTY(&option))) {
		zephir_read_property(&_0$$3, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_array_merge(return_value, &_0$$3, &option TSRMLS_CC);
		RETURN_MM();
	} else {
		RETURN_MM_MEMBER(getThis(), "option");
	}

}

/**
 * 删除单个配置
 *
 * @param string $name
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Log_Log, deleteOption) {

	zval *name_param = NULL, _0, _1$$3;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &name)) {
		zephir_read_property(&_1$$3, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_1$$3, &name, PH_SEPARATE);
	}
	RETURN_THIS();

}

/**
 * 删除多个配置
 *
 * @param array $option
 * @return $this
 */
PHP_METHOD(Queryyetsimple_Log_Log, deleteOptions) {

	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *option_param = NULL, key, *_0;
	zval option;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&option);
	ZVAL_UNDEF(&key);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &option_param);

	if (!option_param) {
		ZEPHIR_INIT_VAR(&option);
		array_init(&option);
	} else {
		zephir_get_arrval(&option, option_param);
	}


	if (!(ZEPHIR_IS_EMPTY(&option))) {
		RETURN_THIS();
	}
	zephir_is_iterable(&option, 0, "queryyetsimple/log/log.zep", 489);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&option), _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		ZVAL_COPY(&key, _0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "deleteoption", &_1, 0, &key);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&key);
	RETURN_THIS();

}

/**
 * 存储日志
 *
 * @param array $arrData
 * @return void
 */
PHP_METHOD(Queryyetsimple_Log_Log, saveStore) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *arrData_param = NULL, _0, _3, _1$$3, _2$$3;
	zval arrData;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&arrData);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &arrData_param);

	zephir_get_arrval(&arrData, arrData_param);


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("calProcessor"), PH_NOISY_CC);
	if (Z_TYPE_P(&_0) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_read_property(&_2$$3, this_ptr, SL("calProcessor"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_USER_FUNC_ARRAY(&_1$$3, &_2$$3, &arrData);
		zephir_check_call_status();
	}
	zephir_read_property(&_3, this_ptr, SL("oConnect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_3, "save", NULL, 0, &arrData);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * 格式化日志消息
 *
 * @param mixed $mixMessage
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Log_Log, formatMessage) {

	zend_bool _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *mixMessage, mixMessage_sub, _2$$3, _3$$5, _4$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mixMessage_sub);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &mixMessage);



	_0 = Z_TYPE_P(mixMessage) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(mixMessage, queryyetsimple_support_ijson_ce TSRMLS_CC);
	}
	_1 = Z_TYPE_P(mixMessage) == IS_OBJECT;
	if (_1) {
		_1 = zephir_instance_of_ev(mixMessage, queryyetsimple_support_iarray_ce TSRMLS_CC);
	}
	if (Z_TYPE_P(mixMessage) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_var_export_ex(&_2$$3, mixMessage TSRMLS_CC);
		RETURN_CCTOR(&_2$$3);
	} else if (_0) {
		ZEPHIR_RETURN_CALL_METHOD(mixMessage, "tojson", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	} else if (_1) {
		ZEPHIR_CALL_METHOD(&_3$$5, mixMessage, "toarray", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$5);
		zephir_var_export_ex(&_4$$5, &_3$$5 TSRMLS_CC);
		RETURN_CCTOR(&_4$$5);
	} else if (zephir_is_scalar(mixMessage)) {
		RETVAL_ZVAL(mixMessage, 1, 0);
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_RuntimeException, "Message is invalid", "queryyetsimple/log/log.zep", 525);
	return;

}

/**
 * call 
 *
 * @param string $sMethod
 * @param array $arrArgs
 * @return mixed
 */
PHP_METHOD(Queryyetsimple_Log_Log, __call) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval arrArgs, _0;
	zval *sMethod_param = NULL, *arrArgs_param = NULL, _1;
	zval sMethod;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sMethod);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&arrArgs);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sMethod_param, &arrArgs_param);

	zephir_get_strval(&sMethod, sMethod_param);
	zephir_get_arrval(&arrArgs, arrArgs_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, SL("oConnect"), PH_NOISY_CC);
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&_0, &sMethod);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, &arrArgs);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object *zephir_init_properties_Queryyetsimple_Log_Log(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3, _2$$3;
	zval __$true, _0, _4, _3$$3, _5$$4;
		ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("option"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 3, 0 TSRMLS_CC);
			zephir_array_update_string(&_1$$3, SL("enabled"), &__$true, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_VAR(&_2$$3);
			zephir_create_array(&_2$$3, 9, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "debug");
			zephir_array_fast_append(&_2$$3, &_3$$3);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "info");
			zephir_array_fast_append(&_2$$3, &_3$$3);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "notice");
			zephir_array_fast_append(&_2$$3, &_3$$3);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "warning");
			zephir_array_fast_append(&_2$$3, &_3$$3);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "error");
			zephir_array_fast_append(&_2$$3, &_3$$3);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "critical");
			zephir_array_fast_append(&_2$$3, &_3$$3);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "alert");
			zephir_array_fast_append(&_2$$3, &_3$$3);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "emergency");
			zephir_array_fast_append(&_2$$3, &_3$$3);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "sql");
			zephir_array_fast_append(&_2$$3, &_3$$3);
			zephir_array_update_string(&_1$$3, SL("level"), &_2$$3, PH_COPY | PH_SEPARATE);
			add_assoc_stringl_ex(&_1$$3, SL("time_format"), SL("[Y-m-d H:i]"));
			zephir_update_property_zval(this_ptr, SL("option"), &_1$$3);
		}
		zephir_read_property(&_4, this_ptr, SL("arrLog"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$4);
			array_init(&_5$$4);
			zephir_update_property_zval(this_ptr, SL("arrLog"), &_5$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

