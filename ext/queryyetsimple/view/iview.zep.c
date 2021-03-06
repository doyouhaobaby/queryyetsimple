
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


/**
 * iview 接口
 *
 * @author Xiangmin Liu <635750556@qq.com>
 * @package $$
 * @since 2018.01.10
 * @version 1.0
 */
ZEPHIR_INIT_CLASS(Queryyetsimple_View_Iview) {

	ZEPHIR_REGISTER_INTERFACE(Queryyetsimple\\View, Iview, queryyetsimple, view_iview, NULL);

	return SUCCESS;

}

