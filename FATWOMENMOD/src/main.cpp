#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
using namespace geode::prelude;

int g_clickCount = 0;

class $modify(FatWomenMenu, MenuLayer) {
    CCSprite* m_fatImage;
    CCLabelBMFont* m_clickLabel;

    bool init() override {
        if (!MenuLayer::init()) return false;

        // Загружаем картинку
        m_fatImage = CCSprite::create("fatwoman.png"_spr);
        if (m_fatImage) {
            m_fatImage->setScale(0.4f);
            m_fatImage->setPosition(
                Mod::get()->getSettingValue<double>("position-x"),
                Mod::get()->getSettingValue<double>("position-y")
            );
            this->addChild(m_fatImage);
        }

        // Счётчик кликов
        m_clickLabel = CCLabelBMFont::create("Clicks: 0", "bigFont.fnt");
        m_clickLabel->setScale(0.5f);
        m_clickLabel->setPosition({350, 50});
        this->addChild(m_clickLabel);

        return true;
    }

    void ccTouchBegan(CCTouch*, CCEvent*) override {
        g_clickCount++;
        m_clickLabel->setString(fmt::format("Clicks: {}", g_clickCount).c_str());
        MenuLayer::ccTouchBegan(nullptr, nullptr); // вызываем оригинальный обработчик
    }
};
