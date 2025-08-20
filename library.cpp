//
// Created by guan on 2025/8/20.
//
#include "library.h"
#include <print>
#include <utility>
#include <vector>

unsigned int Book::total_books = 0;
Book::Book(std::string name, std::string author, std::string isbn):
name(std::move(name)),author(std::move(author)),isbn(std::move(isbn)){
    is_borrowed = false;
    total_books++;
}

Book::Book(const Book& book) :
name(book.name), author(book.author), isbn(book.isbn), is_borrowed(book.is_borrowed){
}

Book::~Book() {
    total_books--;
}

std::string Book::get_info() const{
    std::string info = "name:";
    info += name;
    info+="\n";
    info += "author:";
    info += author;
    info+="\n";
    info += "isbn:";
    info += isbn;
    info+="\n";
    if (is_borrowed) {
        info += "is_borrowed:yes";
    }else {
        info += "is_borrowed:no";
    }
    return info;
}

void Book::borrow() {
    if (is_borrowed) {
        throw std::runtime_error("Already borrowed");
    }
    is_borrowed = true;
}

void Book::return_book() {
    if (!is_borrowed) {
        throw std::runtime_error("Not borrowed");
    }
    is_borrowed = false;
}

unsigned int Book::get_total() {
    return total_books;
}

void print_book_detail(Book& book) {
    std::println("{}",book.get_info());
}

Reader::Reader(unsigned int id, std::string name):
id(id),name(std::move(name)){
}

Reader::~Reader() = default;

std::string Reader::get_reader_info()  const{
    std::string info = "id:"+std::to_string(id)+"\n"+"name:"+name;
    return info;
}

bool StudentReader::check_borrow_limit() const {
    return current_borrow<max_borrow;
}

StudentReader::StudentReader(unsigned int id, std::string name):Reader(id,std::move(name)) {
    max_borrow=3;
    current_borrow=0;
}

StudentReader::~StudentReader()=default;

void StudentReader::return_book(Book& book) {
    book.return_book();
    current_borrow--;
}

void StudentReader::borrow_book(Book& book) {
    if (!check_borrow_limit()) {
        throw std::runtime_error("Borrow limit exceeded");
    }


    book.borrow();
    current_borrow++;
}

bool TeacherReader::check_borrow_limit() const {
    return current_borrow<max_borrow;
}

TeacherReader::TeacherReader(unsigned int id, std::string name) :
Reader(id,std::move(name)){
    max_borrow=5;
    current_borrow=0;
}

TeacherReader::~TeacherReader() =default;

void TeacherReader::return_book(Book& book) {
    book.return_book();
    current_borrow--;
}

void TeacherReader::borrow_book(Book& book) {
    if (!check_borrow_limit()) {
        throw std::runtime_error("Borrow limit exceeded");
    }
    book.borrow();
    current_borrow++;
}

Library::Library() = default;

Library::~Library() {
    for (auto reader : readers) {
        delete reader;
    }
}

void Library::add_reader(Reader* reader) {
    readers.push_back(reader);
}

void Library::add_book(Book& book) {
    books.push_back(book);
}

void Library::show_all_books() const{
    for (const auto& book: books) {
        std::println("{}",book.get_info());
    }
}

std::string Book::get_isbn() const {
    return this->isbn;
}

void Library::show_all_readers() const{
    for (const auto reader: readers) {
        std::println("{}",reader->get_reader_info());
    }
}

Book* Library::find_book_by_isbn(const std::string& isbn) {
    Book *temp=nullptr;
    for (auto &book: books) {
        if (book.get_isbn()==isbn) {
            temp=&book;
            break;
        }
    }
    return temp;
}
