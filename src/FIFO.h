#ifndef _FIFO__H_
#define _FIFO__H_

#include <Arduino.h>

/**
 * FIFO
 *
 * This class implements a FIFO (first-in/first-out) buffer for holding data
 * bytes being transferred between two points, where the incoming and outgoing
 * flows are not synchronized.  The FIFO is implemented with a ring buffer.
 *
 * A FIFO object is declared with a maximum byte capacity.  The FIFO starts out
 * empty and remains so until the application "pushes" a byte into the FIFO.
 * Additional bytes can be pushed into the FIFO; if a push happens when the
 * FIFO is full, the oldest byte in the FIFO is discarded.  At any time, the
 * first byte in the FIFO may be "popped" out.  Popping from an empty FIFO
 * still returns a value (zero), so it's best to test if the FIFO is empty
 * BEFORE performing a pop.
 *
 * Besides the push and pop methods, this class provides methods to:
 *  - clear the FIFO of its contents
 *  - test if the FIFO is empty
 *  - test if the FIFO is full
 */
class FIFO
{
    private:
        unsigned int m_capacity;    // maximum bytes FIFO can hold
        byte*        m_buffer;      // pointer to buffer memory
        byte*        m_head;        // head pointer, where next pop will occur
        byte*        m_tail;        // tail pointer, where next push will occur
        bool         m_empty;       // true if buffer is empty
        bool         m_full;        // true if buffer is full
        
    public:
        /**
         * Constructor
         *
         * Allocates buffer memory and initializes object.
         *
         * @param capacity maximum number of bytes buffer will hold
         */
        FIFO(const unsigned int capacity);
        
        /**
         * Destructor
         */
        virtual ~FIFO();
        
        /**
         * Clear contents of buffer
         *
         * This method resets the head and tail pointers, and marks the buffer
         * as empty and not-full.
         */
        virtual void clear();
        
        /**
         * Push a byte into the tail of the FIFO
         *
         * The pushed byte can only be popped out of the FIFO after all bytes
         * already pushed in are popped out first.  If the FIFO is already
         * full before the push, then the byte at the head of the FIFO will
         * be lost.  If this is not desired, check whether the FIFO is full
         * BEFORE performing the push.
         *
         * @param b byte to be pushed into the buffer
         */
        virtual void push(byte b);
        
        /**
         * Pop a byte from the head of the FIFO
         *
         * If the FIFO is not empty, the byte pushed in earliest will be
         * popped out and returned.  If the FIFO is empty, a zero byte will be
         * returned.  If this is not the desired behavior, check whether the
         * FIFO is empty BEFORE performing the pop.
         *
         * @return byte popped from the buffer
         */
        virtual byte pop();
        
        /**
         * Check if the FIFO is empty
         *
         * @return true if empty, false otherwise
         */
        virtual bool isEmpty() const;
        
        /**
         * Check if the FIFO is full
         *
         * @return true if full, false otherwise
         */
        virtual bool isFull() const;
};

#endif
