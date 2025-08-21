// #include "linked_queue.h"
// #include <print>
// #include "linked_stack.h"
//
//
// int main() {
//     auto queue=LinkedQueue<double>();
//     queue.display();
//     queue.push(1.1);
//     queue.push(2.36);
//     queue.push(3e-8);
//     queue.display();
//     std::println("{}", queue.pop());//1
//     std::println("{}", queue.peek());//2
//     std::println("{}", queue.pop());//2
//     std::println("{}", queue.peek());//3
//     queue.display();
//     std::println("{}", queue.get_size());
//     std::println("------------------------------------------------" );
//     auto stack = LinkedStack<std::string>();
//     stack.display();
//     stack.push("7");
//     stack.push("8");
//     stack.push("9");
//     stack.display();
//     std::println("{}", stack.pop());  // 3
//     std::println("{}", stack.peek()); // 2
//     std::println("{}", stack.pop());  // 2
//     std::println("{}", stack.peek()); // 1
//     stack.display();
//     std::println("{}", stack.get_size());  // 1
//     return 0;
//
//
// }
//

// #include "library.h"
// #include <print>
// #include <stdexcept>
//
// int main() {
//     try {
//         // 创建图书馆
//         Library lib;
//         // 添加3本图书
//         Book b1("C++入门", "张三", "ISBN1001");
//         Book b2("数据结构", "李四", "ISBN1002");
//         Book b3("计算机基础", "王五", "ISBN1003");
//         lib.add_book(b1);
//         lib.add_book(b2);
//         lib.add_book(b3);
//         std::println("=== 图书总数: {} ===", Book::get_total());
//         std::println("=== 所有图书 ===");
//         lib.show_all_books();
//         // 添加读者
//         Reader* student = new StudentReader(1, "学生甲");
//         Reader* teacher = new TeacherReader(2, "教师乙");
//         lib.add_reader(student);
//         lib.add_reader(teacher);
//         std::println("\n=== 所有读者 ===");
//         lib.show_all_readers();
//         // 借书测试
//         std::println("\n=== 借书操作 ===");
//         Book* b1_ptr = lib.find_book_by_isbn("ISBN1001");
//         Book* b2_ptr = lib.find_book_by_isbn("ISBN1002");
//         if (b1_ptr) student->borrow_book(*b1_ptr);
//         if (b2_ptr) teacher->borrow_book(*b2_ptr);
//         std::println("=== 借书后图书状态 ===");
//         lib.show_all_books();
//
//         // 还书测试
//         std::println("\n=== 还书操作 ===");
//         if (b1_ptr) student->return_book(*b1_ptr);
//
//         std::println("=== 还书后图书状态 ===");
//         lib.show_all_books();
//
//         // 友元函数测试
//         std::println("\n=== 图书详情 ===");
//         if (b1_ptr) print_book_detail(*b1_ptr);
//
//     } catch (const std::runtime_error& e) {
//         std::println("错误: {}", e.what());
//         return 1;
//     }
//
//     return 0;
// }


#include "dynamic_array.h"
#include <print>
int main() {
    auto arr=DynamicArray<int,2>();
    arr.push_back(1);
    arr.push_back(2);
    std::println("{}",arr.capacity());
    arr.push_back(3);
    std::println("{}",arr.get(2));
    arr.push_back(4);
    std::println("{}",arr.capacity());
    std::println("{}",arr.size());
    arr.push_back(5);
    arr.display();
    std::println("{}",find(arr,1));
    auto arr1=DynamicArray<int,2>();
    arr1.push_back(1);
    arr1.push_back(2);
    arr1.push_back(3);
    auto arr2=concat(arr,arr1);
    arr2.display();
    try {
        int a=arr.get(10);
    }catch(const std::out_of_range& e) {
        std::print("{}",e.what());
    }

}


