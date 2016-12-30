/**
 * Rewrite heapsort so that it sorts only iterms that are in the range
 * low to high which are passed as additional parameters.
 */
#ifndef __CH7_HEAPSORT_HPP__
#define __CH7_HEAPSORT_HPP__

#include <vector>
#include <utility>

template <typename T>
void print_vector(std::vector<T> v);

inline int left_child( int i, int low ) {
    return 2 * ( i - low ) + 1 + low;
}

template <typename Comparable>
void percolate_down( std::vector<Comparable> & a, int hole, int low, int high ) {
    Comparable tmp = std::move( a[ hole ] );

    int child = left_child( hole, low );
    for(; child <= high; child = left_child( hole, low ) ) {
        if( child < high && a[ child ] < a[ child + 1 ] )
            ++child; // let child be the index of larger children.

        if( tmp < a[ child ] )
            a[ hole ] = std::move( a[ child ] );
        else {
            break;
        }

        hole = child;
    }

    a[ hole ] = std::move( tmp );
}

template <typename Comparable>
void heap_sort(std::vector<Comparable> &a, int low, int high ) {
    /* maxHeap initialization */
    int last_nonleaf_node_number = ( high - low + 1 ) / 2 - 1 + low;
    for( int i = last_nonleaf_node_number; i >= low; --i )
        percolate_down( a, i, low, high );

    /* delete_max */
    for( int j = high; j > low; --j )
    {
        std::swap( a[ low ], a[ j ] );	// swap first (max) with last (min)
        percolate_down( a, low, low, j-1 );	// percolate_down on a array smaller by 1.
    }
}

#endif
