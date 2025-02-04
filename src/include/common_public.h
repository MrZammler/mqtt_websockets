#ifndef MQTT_WEBSOCKETS_COMMON_PUBLIC_H
#define MQTT_WEBSOCKETS_COMMON_PUBLIC_H
/* free_fnc_t in general (in whatever function or struct it is used)
 * decides how the related data will be handled.
 * - If NULL the data are copied internally (causing malloc and later free)
 * - If pointer provided the free function pointed will be called when data are no longer needed
 *   to free associated memory. This is effectively transfering ownership of that pointer to the library.
 *   This also allows caller to provide custom free function other than system one.
 * - If == CALLER_RESPONSIBILITY the library will not copy the data pointed to and will not call free
 *   at the end. This is usefull to avoid copying memory (and associated malloc/free) when data are for
 *   example static. In this case caller has to guarantee the memory pointed to will be valid for entire duration
 *   it is needed. For example by freeing the data after PUBACK is received or by data being static.
 */
typedef void (*free_fnc_t)(void *ptr);
void _caller_responsibility(void *ptr);
#define CALLER_RESPONSIBILITY ((free_fnc_t)&_caller_responsibility)

#endif /* MQTT_WEBSOCKETS_COMMON_PUBLIC_H */
