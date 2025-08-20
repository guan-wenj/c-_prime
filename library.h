//
// Created by guan on 2025/8/20.
//

#ifndef C__PRIME_LIBRARY_H
#define C__PRIME_LIBRARY_H
#include <string>
#include <vector>

// Book 类：
//     私有成员：书名（name）、作者（author）、ISBN 号（isbn）、是否被借出（isBorrowed）。
//     公有构造函数：带参构造（初始化书名、作者、ISBN）、拷贝构造。
//     公有成员函数：获取图书信息（getInfo()）、借阅图书（borrow()）、归还图书（returnBook()）。
//     静态成员：图书总数量（totalBooks），并提供静态函数getTotalBooks()返回总数量。
//     友元函数：printBookDetail(Book&)，用于打印图书的详细信息（可访问私有成员）。

class Book {
    static unsigned int total_books;
    std::string name;
    std::string author;
    std::string isbn;
    bool is_borrowed;
    public:
    Book(std::string name, std::string author, std::string isbn);
    Book(const Book &book);
    ~Book();
    std::string get_info() const;
    std::string get_isbn() const;
    void borrow();
    void return_book();
    static unsigned int get_total();
    friend void print_book_detail(Book &book) ;
};


// Reader 类（抽象类）：
//     保护成员：读者 ID（id）、姓名（name）。
//     公有构造函数：带参构造（初始化 ID、姓名）。
//     纯虚函数：borrowBook(Book&)（借阅图书）、returnBook(Book&)（归还图书）。
//     虚析构函数（确保派生类析构正常调用）。
//     公有成员函数：getReaderInfo()（返回读者基本信息）。
class Reader {
    protected:
    unsigned int id;
    std::string name;
    public:
    Reader(unsigned int id,std::string name);
    virtual ~Reader();
    virtual void borrow_book(Book& book)=0;
    virtual void return_book(Book& book)=0;
    std::string get_reader_info() const;
};

// StudentReader 类（继承 Reader）：
//     私有成员：最大可借数量（固定为 3 本，maxBorrow）、当前已借数量（currentBorrow）。
//     公有构造函数：带参构造（初始化 ID、姓名）。
//     重写纯虚函数：borrowBook(Book&)（需判断是否超过最大可借数量）、returnBook(Book&)。
//     私有成员函数：checkBorrowLimit()（检查是否可继续借书）。
class StudentReader : public Reader {
    unsigned int max_borrow;
    unsigned int current_borrow;
    bool check_borrow_limit() const;
    public:
    StudentReader(unsigned int id, std::string name);
    ~StudentReader() override;
    void return_book(Book& book) override;
    void borrow_book(Book& book) override;
};


// TeacherReader 类（继承 Reader）：
//     私有成员：最大可借数量（固定为 5 本，maxBorrow）、当前已借数量（currentBorrow）。
//     公有构造函数：带参构造（初始化 ID、姓名）。
//     重写纯虚函数：borrowBook(Book&)、returnBook(Book&)（逻辑与学生类似，但数量限制不同）。

class TeacherReader : public Reader {
    unsigned int max_borrow;
    unsigned int current_borrow;
    bool check_borrow_limit() const;
    public:
    TeacherReader(unsigned int id, std::string name);
    ~TeacherReader() override;
    void return_book(Book& book) override;
    void borrow_book(Book& book) override;
};

// Library 类：
//     私有成员：图书列表（std::vector<Book>）、读者列表（std::vector<Reader*>，存储派生类对象指针）。
//     公有成员函数：
//         addBook(Book&)（添加图书到图书馆）
//         addReader(Reader*)（添加读者到图书馆）
//         showAllBooks()（显示所有图书信息）
//         showAllReaders()（显示所有读者信息）
//         findBookByISBN(std::string)（根据 ISBN 查找图书，返回指针）

class Library {
    std::vector<Book> books;
    std::vector<Reader*> readers;
    public:
    Library();
    ~Library();
    void add_reader(Reader* reader);
    void add_book(Book &book);
    void show_all_books() const;
    void show_all_readers() const;
    Book* find_book_by_isbn(const std::string& isbn);
};









#endif //C__PRIME_LIBRARY_H