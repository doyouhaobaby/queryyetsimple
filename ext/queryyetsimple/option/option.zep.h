
extern zend_class_entry *queryyetsimple_option_option_ce;

ZEPHIR_INIT_CLASS(Queryyetsimple_Option_Option);

PHP_METHOD(Queryyetsimple_Option_Option, __construct);
PHP_METHOD(Queryyetsimple_Option_Option, has);
PHP_METHOD(Queryyetsimple_Option_Option, get);
PHP_METHOD(Queryyetsimple_Option_Option, all);
PHP_METHOD(Queryyetsimple_Option_Option, set);
PHP_METHOD(Queryyetsimple_Option_Option, delete);
PHP_METHOD(Queryyetsimple_Option_Option, reset);
PHP_METHOD(Queryyetsimple_Option_Option, offsetExists);
PHP_METHOD(Queryyetsimple_Option_Option, offsetGet);
PHP_METHOD(Queryyetsimple_Option_Option, offsetSet);
PHP_METHOD(Queryyetsimple_Option_Option, offsetUnset);
PHP_METHOD(Queryyetsimple_Option_Option, setRecursion);
PHP_METHOD(Queryyetsimple_Option_Option, deleteRecursion);
PHP_METHOD(Queryyetsimple_Option_Option, parseNamespace);
zend_object *zephir_init_properties_Queryyetsimple_Option_Option(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_option_option___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_option_option_has, 0, 0, 0)
	ZEND_ARG_INFO(0, sName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_option_option_get, 0, 0, 0)
	ZEND_ARG_INFO(0, sName)
	ZEND_ARG_INFO(0, mixDefault)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_option_option_set, 0, 0, 1)
	ZEND_ARG_INFO(0, mixName)
	ZEND_ARG_INFO(0, mixValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_option_option_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, sName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_option_option_reset, 0, 0, 0)
	ZEND_ARG_INFO(0, mixNamespace)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_option_option_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, strName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_option_option_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, strName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_option_option_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, strName)
	ZEND_ARG_INFO(0, mixValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_option_option_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, strName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_option_option_setrecursion, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, arrPart, 0)
	ZEND_ARG_INFO(0, mixValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_option_option_deleterecursion, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, arrPart, 0)
	ZEND_ARG_ARRAY_INFO(0, arrResult, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_queryyetsimple_option_option_parsenamespace, 0, 0, 1)
	ZEND_ARG_INFO(0, strName)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(queryyetsimple_option_option_method_entry) {
	PHP_ME(Queryyetsimple_Option_Option, __construct, arginfo_queryyetsimple_option_option___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Queryyetsimple_Option_Option, has, arginfo_queryyetsimple_option_option_has, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Option_Option, get, arginfo_queryyetsimple_option_option_get, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Option_Option, all, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Option_Option, set, arginfo_queryyetsimple_option_option_set, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Option_Option, delete, arginfo_queryyetsimple_option_option_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Option_Option, reset, arginfo_queryyetsimple_option_option_reset, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Option_Option, offsetExists, arginfo_queryyetsimple_option_option_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Option_Option, offsetGet, arginfo_queryyetsimple_option_option_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Option_Option, offsetSet, arginfo_queryyetsimple_option_option_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Option_Option, offsetUnset, arginfo_queryyetsimple_option_option_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Queryyetsimple_Option_Option, setRecursion, arginfo_queryyetsimple_option_option_setrecursion, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Option_Option, deleteRecursion, arginfo_queryyetsimple_option_option_deleterecursion, ZEND_ACC_PROTECTED)
	PHP_ME(Queryyetsimple_Option_Option, parseNamespace, arginfo_queryyetsimple_option_option_parsenamespace, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
