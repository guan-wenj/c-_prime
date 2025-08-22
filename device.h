//
// Created by guan on 2025/8/22.
//

#ifndef C__PRIME_DEVICE_H
#define C__PRIME_DEVICE_H
#include <string>
#include <print>

/*
设计基础类 Device（设备）：

    包含私有成员 brand（品牌）和 price（价格）
    纯虚函数 getType() 返回设备类型（字符串）
    普通成员函数 getPrice() 返回价格

派生两个类：

    Smartphone（智能手机）：添加私有成员 storage（存储容量，单位 GB），getType() 返回 "智能手机"
    Laptop（笔记本电脑）：添加私有成员 ram（内存大小，单位 GB），getType() 返回 "笔记本电脑"

设计友元类 DeviceManager：

    作为 Device 类的友元，可以访问其私有成员
    实现 showDeviceDetails(Device* device) 方法：使用 RTTI 判断设备具体类型，打印完整信息（包括品牌、价格和对应设备的特有属性）
    实现 checkDevice(Device* device) 方法：检查设备信息有效性，若品牌为空或价格≤0，抛出异常（可使用标准异常或自定义异常）

在主函数中：

    创建至少两个不同类型的设备对象
    故意创建一个无效设备（如价格为负数），捕获并处理异常
    使用 DeviceManager 展示所有有效设备的详细信息
    */
/**
 * @brief 设备类
 */



class DeviceException : public std::exception {
protected:
    std::string message; // 异常描述信息
public:
    // 构造函数：接收异常信息
    explicit DeviceException(const std::string& msg) : message(msg) {}

    // 重写what()方法，返回异常信息（const char*类型）
    const char* what() const noexcept override {
        return message.c_str();
    }
};




class DeviceManager;


class Device {
    friend class DeviceManager;
    std::string brand;
    double price;
    public:
    Device(std::string brand, double price);
    virtual ~Device()=default;
    virtual std::string get_type() const=0;
    double get_price() const;
};


class SmartPhone : public Device {
    int storage;
    public:
    SmartPhone(std::string brand, double price, int storage);
    ~SmartPhone()=default;
    std::string get_type() const override;
    int get_storage() const;
};

class Laptop : public Device {
    int ram;
    public:
    Laptop(std::string brand, double price, int ram);
    ~Laptop()=default;
    std::string get_type() const override;
    int get_ram() const;
};

class DeviceManager {
    public:
    DeviceManager()=default;
    ~DeviceManager()=default;
    void showDeviceDetails(Device* device);
    void checkDevice(Device* device);
};


inline Device::Device(std::string brand, double price):brand(brand),price(price) {
}

inline double Device::get_price() const {
    return price;
}

inline int SmartPhone::get_storage() const {
    return storage;
}

inline int Laptop::get_ram() const {
    return ram;
}

inline SmartPhone::SmartPhone(std::string brand, double price, int storage):Device(brand,price),storage(storage) {
}

inline std::string SmartPhone::get_type() const {
    return "SmartPhone";
}

inline Laptop::Laptop(std::string brand, double price, int ram):Device(brand,price),ram(ram) {

}

inline std::string Laptop::get_type() const {
    return "Laptop";
}

inline void DeviceManager::showDeviceDetails(Device* device) {
    std::print("brand:");
    std::print("{}\n",device->brand);
    std::print("price:");
    std::print("{}\n",device->price);
    std::print("type:");
    std::print("{}\n",device->get_type());
    if (typeid(*device) == typeid(SmartPhone)) {
        auto* smartphone = dynamic_cast<SmartPhone*>(device);
        std::print("storage:");
        std::print("{}\n",smartphone->get_storage());
    }
    else if (typeid(*device) == typeid(Laptop)) {
        auto* laptop = dynamic_cast<Laptop*>(device);
        std::print("ram:");
        std::print("{}\n",laptop->get_ram());
    }
}

inline void DeviceManager::checkDevice(Device* device) {
    if (device==nullptr) {
        throw std::invalid_argument("null device");
    }

    if (device->price<0.0) {
        throw DeviceException("Can't determine what price was created");
    }
    if (device->brand.empty()) {
        throw DeviceException("Can't determine what brand was created");
    }
}


#endif //C__PRIME_DEVICE_H
