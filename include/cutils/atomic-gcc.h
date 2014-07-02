/*
 * Copyright (C) 2010 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANDROID_CUTILS_ATOMIC_GCC_H
#define ANDROID_CUTILS_ATOMIC_GCC_H

#include <stdint.h>

#ifndef ANDROID_ATOMIC_INLINE
#define ANDROID_ATOMIC_INLINE inline __attribute__((always_inline))
#endif

extern ANDROID_ATOMIC_INLINE void android_compiler_barrier(void)
{
    __sync_synchronize();
}

extern ANDROID_ATOMIC_INLINE void android_memory_barrier(void)
{
    android_compiler_barrier();
}
extern ANDROID_ATOMIC_INLINE void android_memory_store_barrier(void)
{
    android_compiler_barrier();
}

extern ANDROID_ATOMIC_INLINE int32_t
android_atomic_acquire_load(volatile const int32_t *ptr)
{
    int32_t value = *ptr;
    android_compiler_barrier();
    return value;
}

extern ANDROID_ATOMIC_INLINE intptr_t
android_atomic_acquire_load_ip(volatile const intptr_t *ptr)
{
    intptr_t value = *ptr;
    android_compiler_barrier();
    return value;
}

extern ANDROID_ATOMIC_INLINE int32_t
android_atomic_release_load(volatile const int32_t *ptr)
{
    android_memory_barrier();
    return *ptr;
}

extern ANDROID_ATOMIC_INLINE intptr_t
android_atomic_release_load_ip(volatile const intptr_t *ptr)
{
    android_memory_barrier();
    return *ptr;
}

extern ANDROID_ATOMIC_INLINE void
android_atomic_acquire_store(int32_t value, volatile int32_t *ptr)
{
    *ptr = value;
    android_memory_barrier();
}

extern ANDROID_ATOMIC_INLINE void
android_atomic_acquire_store_ip(intptr_t value, volatile intptr_t *ptr)
{
    *ptr = value;
    android_memory_barrier();
}

extern ANDROID_ATOMIC_INLINE void
android_atomic_release_store(int32_t value, volatile int32_t *ptr)
{
    android_compiler_barrier();
    *ptr = value;
}

extern ANDROID_ATOMIC_INLINE void
android_atomic_release_store_ip(intptr_t value, volatile intptr_t *ptr)
{
    android_compiler_barrier();
    *ptr = value;
}

extern ANDROID_ATOMIC_INLINE int
android_atomic_cas(int32_t old_value, int32_t new_value, volatile int32_t *ptr)
{
	return __sync_bool_compare_and_swap(ptr, old_value, new_value);
}

extern ANDROID_ATOMIC_INLINE int
android_atomic_acquire_cas(int32_t old_value,
                           int32_t new_value,
                           volatile int32_t *ptr)
{
    /* Loads are not reordered with other loads. */
    return android_atomic_cas(old_value, new_value, ptr);
}

extern ANDROID_ATOMIC_INLINE int
android_atomic_acquire_cas_ip(intptr_t old_value,
                           intptr_t new_value,
                           volatile intptr_t *ptr)
{
    return __sync_bool_compare_and_swap(ptr, old_value, new_value);
}


extern ANDROID_ATOMIC_INLINE int
android_atomic_release_cas(int32_t old_value,
                           int32_t new_value,
                           volatile int32_t *ptr)
{
    /* Stores are not reordered with other stores. */
    return android_atomic_cas(old_value, new_value, ptr);
}

extern ANDROID_ATOMIC_INLINE int
android_atomic_release_cas_ip(intptr_t old_value,
                           intptr_t new_value,
                           volatile intptr_t *ptr)
{
    /* Stores are not reordered with other stores. */
    return __sync_bool_compare_and_swap(ptr, old_value, new_value);
}

extern ANDROID_ATOMIC_INLINE int32_t
android_atomic_add(int32_t increment, volatile int32_t *ptr)
{
	return __sync_fetch_and_add(ptr, increment);
}

extern ANDROID_ATOMIC_INLINE int32_t
android_atomic_inc(volatile int32_t *addr)
{
    return android_atomic_add(1, addr);
}

extern ANDROID_ATOMIC_INLINE int32_t
android_atomic_dec(volatile int32_t *addr)
{
    return android_atomic_add(-1, addr);
}

extern ANDROID_ATOMIC_INLINE int32_t
android_atomic_and(int32_t value, volatile int32_t *ptr)
{
 	return __sync_fetch_and_and(ptr, value);
}

extern ANDROID_ATOMIC_INLINE int32_t
android_atomic_or(int32_t value, volatile int32_t *ptr)
{
    return __sync_fetch_and_or(ptr, value);
}

#endif /* ANDROID_CUTILS_ATOMIC_GCC_H */
