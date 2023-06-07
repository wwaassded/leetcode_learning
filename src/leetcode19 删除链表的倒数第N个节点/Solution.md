# 简单的链表题

删除倒数N节点，先使ptr只向正数的N节点

然后

`

```
while(ptr->next != nullptr) {
      ptr = ptr->next;
      it = it->next;
      head = head->next;
    }
````

head所指的就是倒数N节点，删掉即可
