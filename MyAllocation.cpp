#include "MyAllocation.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//-------------------------------------------------------

void* MyCalloc (size_t n_elems, size_t size_elems, const void* poison)
    {
    void* mem_ptr = calloc (n_elems, size_elems);
    for (size_t i = 0; i < n_elems; i++)
        memcpy ((char*) mem_ptr + i * size_elems, poison, size_elems);
    return mem_ptr;
    }

//-------------------------------------------------------

void* MyRecalloc (void* memory, size_t n_elements, size_t size_elements, size_t previous_n_elements, const void* poison)
    {
    /// Если уменьшаем блок памяти, то удаленные ячейки обнуляем
    if (previous_n_elements > n_elements)
        memset ((char*) memory + n_elements * size_elements, 0, size_elements * (previous_n_elements - n_elements));

    void* save_memory = memory;
    memory = realloc (memory, n_elements * size_elements);
    /// Если память не удалось перевыделить, то освобождаем старый указатель и возвращаем 0
    if (memory == NULL)
        {
        free (save_memory); save_memory = NULL;
        return NULL;
        }

    /// Если увеличиваем блок памяти, то новые ячейки заполняем ядовитым значением
    if (previous_n_elements < n_elements)
        for (size_t i = 0; i < n_elements - previous_n_elements; i++)
            memcpy(((char*) memory + (previous_n_elements + i) * size_elements), poison, size_elements);

    return memory;
    }

//-------------------------------------------------------
