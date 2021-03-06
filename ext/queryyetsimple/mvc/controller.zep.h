
extern zend_class_entry *queryyetsimple_mvc_controller_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Mvc_Controller);

PHP_METHOD(Queryyetsimple_Mvc_Controller, __construct);
PHP_METHOD(Queryyetsimple_Mvc_Controller, setView);
PHP_METHOD(Queryyetsimple_Mvc_Controller, setRouter);
PHP_METHOD(Queryyetsimple_Mvc_Controller, action);
PHP_METHOD(Queryyetsimple_Mvc_Controller, switchView);
PHP_METHOD(Queryyetsimple_Mvc_Controller, assign);
PHP_METHOD(Queryyetsimple_Mvc_Controller, getAssign);
PHP_METHOD(Queryyetsimple_Mvc_Controller, deleteAssign);
PHP_METHOD(Queryyetsimple_Mvc_Controller, clearAssign);
PHP_METHOD(Queryyetsimple_Mvc_Controller, display);
PHP_METHOD(Queryyetsimple_Mvc_Controller, checkView);
PHP_METHOD(Queryyetsimple_Mvc_Controller, __set);
PHP_METHOD(Queryyetsimple_Mvc_Controller, __get);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_controller_setview, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, objView, Queryyetsimple\\Mvc\\Iview, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_controller_setrouter, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, objRouter, Queryyetsimple\\Router\\Router, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_controller_action, 0, 0, 1)
	ZEND_ARG_INFO(0, sActionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_controller_switchview, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, objTheme, Queryyetsimple\\View\\Iview, 0)
	ZEND_ARG_INFO(0, booForever)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_controller_assign, 0, 0, 1)
	ZEND_ARG_INFO(0, mixName)
	ZEND_ARG_INFO(0, mixValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_controller_getassign, 0, 0, 0)
	ZEND_ARG_INFO(0, sName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_controller_deleteassign, 0, 0, 1)
	ZEND_ARG_INFO(0, mixName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_controller_display, 0, 0, 0)
	ZEND_ARG_INFO(0, sFile)
	ZEND_ARG_ARRAY_INFO(0, arrOption, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_controller___set, 0, 0, 2)
	ZEND_ARG_INFO(0, mixName)
	ZEND_ARG_INFO(0, mixValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_mvc_controller___get, 0, 0, 1)
	ZEND_ARG_INFO(0, sName)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_mvc_controller_method_entry) {
	PHP_ME(Queryyetsimple_Mvc_Controller, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Queryyetsimple_Mvc_Controller, setView, arginfo_queryyetsimple_mvc_controller_setview, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Mvc_Controller, setRouter, arginfo_queryyetsimple_mvc_controller_setrouter, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Mvc_Controller, action, arginfo_queryyetsimple_mvc_controller_action, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Mvc_Controller, switchView, arginfo_queryyetsimple_mvc_controller_switchview, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Mvc_Controller, assign, arginfo_queryyetsimple_mvc_controller_assign, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Mvc_Controller, getAssign, arginfo_queryyetsimple_mvc_controller_getassign, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Mvc_Controller, deleteAssign, arginfo_queryyetsimple_mvc_controller_deleteassign, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Mvc_Controller, clearAssign, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Mvc_Controller, display, arginfo_queryyetsimple_mvc_controller_display, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Mvc_Controller, checkView, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Mvc_Controller, __set, arginfo_queryyetsimple_mvc_controller___set, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Mvc_Controller, __get, arginfo_queryyetsimple_mvc_controller___get, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
