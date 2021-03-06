#ifndef REDIS_ARRAY_H
#define REDIS_ARRAY_H

#include <stdint.h>
#include "common.h"

void redis_destructor_redis_array(zend_rsrc_list_entry * rsrc TSRMLS_DC);

PHP_METHOD(RedisArray, __construct);
PHP_METHOD(RedisArray, __call);
PHP_METHOD(RedisArray, _hosts);
PHP_METHOD(RedisArray, _target);
PHP_METHOD(RedisArray, _instance);
PHP_METHOD(RedisArray, _function);
PHP_METHOD(RedisArray, _distributor);
PHP_METHOD(RedisArray, _rehash);

PHP_METHOD(RedisArray, info);
PHP_METHOD(RedisArray, ping);
PHP_METHOD(RedisArray, mget);
PHP_METHOD(RedisArray, mset);
PHP_METHOD(RedisArray, del);
PHP_METHOD(RedisArray, keys);
PHP_METHOD(RedisArray, getOption);
PHP_METHOD(RedisArray, setOption);

PHP_METHOD(RedisArray, multi);
PHP_METHOD(RedisArray, exec);
PHP_METHOD(RedisArray, discard);
PHP_METHOD(RedisArray, unwatch);


typedef struct RedisArray_ {

	int count;
	char **hosts;			/* array of host:port strings */
	zval **redis;			/* array of Redis instances */
	zval *z_multi_exec;		/* Redis instance to be used in multi-exec */
	zend_bool index;		/* use per-node index */
	zend_bool auto_rehash; 	/* migrate keys on read operations */
	zval *z_fun;			/* key extractor, callable */
	zval *z_dist;			/* key distributor, callable */
	zval *z_pure_cmds;		/* hash table */

	struct RedisArray_ *prev;
} RedisArray;

uint32_t rcrc32(const char *s, size_t sz);


#endif
