#include <iostream>

class IDeliveryStrategy {
public:
    virtual float calculateCost(float weight, float distance) = 0; // Метод для расчета стоимости
    virtual ~IDeliveryStrategy() = default; // Виртуальный деструктор
};

class GroundDelivery : public IDeliveryStrategy {
public:
    float calculateCost(float weight, float distance) override {
        const float rate_per_km = 10; // фиксированная ставка за километр
        return rate_per_km * distance;
    }
};

class AirDelivery : public IDeliveryStrategy {
public:
    float calculateCost(float weight, float distance) override {
        const float base_rate = 50; // базовая ставка
        const float weight_rate = 20; // ставка за килограмм
        return base_rate + (weight_rate * weight * distance);
    }
};

class ExpressDelivery : public IDeliveryStrategy {
public:
    float calculateCost(float weight, float distance) override {
        const float base_rate = 100; // фиксированная ставка
        const float urgency_rate = 50; // увеличение стоимости за срочность
        return (base_rate + urgency_rate) * distance;
    }
};

class DeliveryContext {
private:
    IDeliveryStrategy* deliveryStrategy; // Указатель на стратегию

public:
    void setStrategy(IDeliveryStrategy* strategy) {
        deliveryStrategy = strategy; // Устанавливаем выбранную стратегию
    }

    float calculateCost(float weight, float distance) {
        return deliveryStrategy->calculateCost(weight, distance); // Рассчитываем стоимость доставки
    }
};

int main() {
    DeliveryContext deliveryContext; // Создаем объект контекста доставки

    float weight, distance;
    std::cout << "Enter weight: ";
    std::cin >> weight;
    std::cout << "enter distance: ";
    std::cin >> distance;

    // Примеры использования различных стратегий доставки

    GroundDelivery groundDelivery;
    deliveryContext.setStrategy(&groundDelivery);
    std::cout << "Groung delivery costs: " << deliveryContext.calculateCost(weight, distance) << std::endl;

    AirDelivery airDelivery;
    deliveryContext.setStrategy(&airDelivery);
    std::cout << "AirDelivery costs: " << deliveryContext.calculateCost(weight, distance) << std::endl;

    ExpressDelivery expressDelivery;
    deliveryContext.setStrategy(&expressDelivery);
    std::cout << "Express delivery costs: " << deliveryContext.calculateCost(weight, distance) << std::endl;

    return 0;
}



