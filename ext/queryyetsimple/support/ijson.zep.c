
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * ijson 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2017.12.24
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_Support_Ijson) {

	ZEPHIR_REGISTER_INTERFACE(Queryyetsimple\\Support, Ijson, queryyetsimple, support_ijson, queryyetsimple_support_ijson_method_entry);

	return SUCCESS;

}

/**
 * 对象转 JSON
 *
 * @param integer $intOption
 * @return string
 */
ZEPHIR_DOC_METHOD(Queryyetsimple_Support_Ijson, toJson);

