#include <QPushButton>
#include <QComboBox>
#include <QVBoxLayout>
#include <QLabel>
#include <QApplication>
//1. 定义插件接口（工厂方法契约)
class PluginInterface
{
    public:
        virtual ~PluginInterface() = default;
		virtual QWidget* createWidget() = 0; //工厂方法
		virtual QString name() const = 0;

};

//具体插件实现  - 按钮插件
class ButtonPlugin :public PluginInterface
{
public:
    QWidget* createWidget() override {
        QPushButton* btn = new QPushButton("按钮插件");
        btn->setStyleSheet("background-color: lightblue;color:white; padding:10px; font-size: 16px;");
		return btn;
    }

    QString name() const override {
        return "ButtonPlugin";
    }
};
//具体插件实现 - 标签插件
class LabelPlugin : public PluginInterface
{
public:
    QWidget* createWidget() override {
        QLabel* label = new QLabel("标签插件");
        label->setStyleSheet("color: green; font-size: 18px;");
        return label;
    }
    QString name() const override {
        return "LabelPlugin";
    }
};
//4. 插件管理器(模拟插件加载)
class PluginManager
{
    public:
   PluginManager() {
        //模拟加载插件
        plugins.append(new ButtonPlugin());
        plugins.append(new LabelPlugin());
    }
   ~PluginManager()
    {
       for(auto plugin : plugins) {
           delete plugin;
	   }
   }
   QWidget* createWidget(const QString& pluginName) {
        for(auto plugin : plugins) {
            if(plugin->name() == pluginName) {
                return plugin->createWidget();
            }
        }
        return nullptr;
   }
   QStringList getPluginNames() const {
       QStringList names;
       for (auto plugin : plugins) {
           names.append(plugin->name());
       }
       return names;
   }
   QStringList pluginNames() const {
       QStringList names;
       for (auto plugin : plugins) names << plugin->name();
       return names;
   }

private:
	QList<PluginInterface*> plugins;
};
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //创建主窗口
    QWidget window;
    window.setWindowTitle("qt 插件工厂方法");

    window.resize(300, 200);
    QVBoxLayout* layout = new QVBoxLayout(&window);
    // 插件选择
    QComboBox* comboBox = new QComboBox();
    QPushButton* createBtn = new QPushButton("创建组件");
    QWidget* container = new QWidget();
    QVBoxLayout* containerLayout = new QVBoxLayout(container);
    layout->addWidget(comboBox);
    layout->addWidget(createBtn);
    layout->addWidget(container);

    // 初始化插件管理器
    PluginManager pluginManager;
    comboBox->addItems(pluginManager.pluginNames());
    // 连接信号槽
    QObject::connect(createBtn, &QPushButton::clicked, [&]() {
        // 清理旧组件
        QLayoutItem* item;
        while ((item = containerLayout->takeAt(0)) != nullptr) {
            delete item->widget();//  // 删除实际的widget对象
            delete item; //           // 删除QLayoutItem本身
        }
        // 使用工厂方法创建新组件
        QString pluginName = comboBox->currentText();
        if (QWidget* widget = pluginManager.createWidget(pluginName)) {
            containerLayout->addWidget(widget);
        }
        });
    window.show();
    return QCoreApplication::exec();
}
