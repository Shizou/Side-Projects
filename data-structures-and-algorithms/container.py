def ContainerFullException(Exception):
    def __init__(self, message):
      self.message = message


class queue:
    def __init__(self):
        self._queue = []
    def __str__(self):
        return str(self._queue)

    def put(self, item):
       self._queue.append(item)

    def get(self):
       ret = self._queue[0]
       self._queue.pop(0)
       return ret

    def peek(self):
       return self._queue[0]

    def is_empty(self):
       return len(self._queue) == 0


class stack:
    def __init__(self):
        self._stack = []
    def __str__(self):
        return str(self._stack)

    def put(self, item):
       self._stack.append(item)

    def get(self):
       ret = self._stack[-1]
       self._stack.pop()
       return ret

    def peek(self):
       return self._stack[-1]

    def is_empty(self):
       return len(self._stack) == 0


class bucket:
    def __init__(self):
        self._bucket = []
    def __str__(self):
        return str(self._bucket)

    def put(self, item):
       if(len(self._bucket) == 1):
           raise Exception("you dummy")
       else:
           self._bucket.append(item)

    def get(self):
       ret = self._bucket[0]
       self._bucket = []
       return ret

    def peek(self):
       return self._bucket[0]

    def is_empty(self):
       return len(self._queue) == 0


if __name__ == '__main__':
    q = bucket()
    q.put('test')
    q.put('test2')
    print(q.get())
    print(q.peek())
    print(q.is_empty())
    q.get()
    print(q.is_empty())