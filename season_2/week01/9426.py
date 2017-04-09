from collections import deque, namedtuple
import heapq

TemperatureRecord = namedtuple('TemperatureRecord', ['value', 'time'])

class DeletableMinHeap:
    def __init__(self, values):
        # O(N)
        self.heap = heapq.heapify(list(values))

    def push(self, value):
        # O(logN)
        heapq.heappush(self.heap, -value)
    
    def pop(self):
        # O(1)
        return heapq.heappop(self.heap)

    def delete(self, index):
        # O(logN)
        self.heap[index] = self.heap[-1]
        self.heap.pop()
        heapq._siftup(self.heap, index)
        heapq._siftdown(self.heap, 0, index)


class DeletableMaxHeap(DeletableMinHeap):
    def __init__(self, values):
        # O(N)
        self.heap = heapq.heapify([-x for x in values])
    
    def push(self, value):
        # O(logN)
        DeletableMinHeap.push(self, -value)
    
    def pop(self):
        return DeletableMinHeap.pop(self)
    
    def delete(self, index):
        return DeletableHeap.delete(self, -index)


class MedianStream:
    def __init__(self,  max_stream_size):
        self.minHeap = DeletableMinHeap()
        self.maxHeap = DeletableMaxHeap()
        self.max_stream_size = size
        self.size = 0
        self.queue = deque()
        self.heap = None
        self.current_time = 0
        self.current_median = None
    
    def push(self, value):
        current_time += 1
        if self.size == self.max_stream_size - 1:
            self.time_queue.append(value)
            self.heap = list(time_queue)
        if self.size < self.max_stream_size:
            self.size += 1
        else:
            popped_is_smaller = self.deque.popleft() < self.current_median
            value_is_smaller = value < self.current_median
            if value_is_smaller
        self.deque.append(value)
        

    def getMedian(self, value):


if __name__ == '__main__':
    n, k = [int(x) for x in raw_input().split()]
    temperature_record = [int(raw_input()) for _ in xrange(n)]
