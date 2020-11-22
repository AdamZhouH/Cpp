
template <typename elemType> class ListItem;

template <typename elemType>
class List {
public:
  List();
  List(const List &);
  List &operator =(const List &);
  ~List();
  void insert(ListItem<T> *ptr, elemType value);
private:
  ListItem<T> *front, *end;
};
