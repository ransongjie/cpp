#include <iostream>
#include <map>
#include <string>

// 1. 定义原型接口
class Prototype {
public:
    virtual ~Prototype() {}
    virtual Prototype* clone() const = 0;
};

// 2. 实现具体原型
class ConcretePrototypeA : public Prototype {
    std::string value;

public:
    ConcretePrototypeA(const std::string& val) : value(val) {}
    ConcretePrototypeA(const ConcretePrototypeA& other) : value(other.value) {}

    virtual Prototype* clone() const override {
        return new ConcretePrototypeA(*this);
    }

    void display() const {
        std::cout << "Prototype A with value: " << value << std::endl;
    }
};

// 3. 使用原型管理器
class PrototypeManager {
    std::map<std::string, Prototype*> prototypes;

public:
    ~PrototypeManager() {
        for (auto& pair : prototypes) {
            delete pair.second;
        }
        prototypes.clear();
    }

    void registerPrototype(const std::string& id, Prototype* proto) {
        prototypes[id] = proto;
    }

    Prototype* createPrototype(const std::string& id) {
        if (prototypes.find(id) != prototypes.end()) {
            return prototypes[id]->clone();
        }
        return nullptr;
    }
};

int main() {
    PrototypeManager manager;
    ConcretePrototypeA* protoA = new ConcretePrototypeA("Initial Value A");
    manager.registerPrototype("A", protoA);

    // 使用原型创建新对象
    ConcretePrototypeA* cloneA = dynamic_cast<ConcretePrototypeA*>(manager.createPrototype("A"));
    if (cloneA) {
        cloneA->display();
    }

    return 0;
}