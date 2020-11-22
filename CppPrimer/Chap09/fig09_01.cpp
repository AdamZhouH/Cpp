/**
 * a) 按照字典顺序插入容器，考虑中间位置插入比较频繁，使用list比较合适
 * b) 删除头部，尾部插入，头尾的插入删除都要快速，考虑使用双端队列deque
 * c) 考虑先读入，再排序，读的过程总是把数据插入到尾部，然后考虑排序，使用vector合适
 */