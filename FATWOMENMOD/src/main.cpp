#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(FatWomenLayer, MenuLayer) {
    CCSprite* m_image;
    CCLabelBMFont* m_counterLabel;
    static int s_clickCount;

    bool init() override {
        if (!MenuLayer::init()) return false;

        // Картинка
        m_image = CCSprite::create("fatwoman.png"_spr);
        if (m_image) {
            m_image->setScale(0.4f);
            this->addChild(m_image);
            updatePos();
        }

        // Счётчик
        m_counterLabel = CCLabelBMFont::create("Clicks: 0", "bigFont.fnt");
        m_counterLabel->setScale(0.5f);
        m_counterLabel->setPosition({350, 50});
        this->addChild(m_counterLabel);

        return true;
    }

    void updatePos() {
        if (!m_image) return;
        float x = Mod::get()->getSettingValue<double>("position-x");
        float y = Mod::get()->getSettingValue<double>("position-y");
        m_image->setPosition({x, y});
    }

    void ccTouchBegan(CCTouch*, CCEvent*) override {
        s_clickCount++;
        m_counterLabel->setString(fmt::format("Clicks: {}", s_clickCount).c_str());
    }
};

int FatWomenLayer::s_clickCount = 0;