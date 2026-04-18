#include "mainwindow.h"
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    :m_count{ 0 }, QMainWindow(parent)
{
    m_CountLabel = new QLabel(this);
}

MainWindow::~MainWindow() = default;

void MainWindow::OnIncrementClicked()
{
    m_count ++;
    m_CountLabel = new QLabel(this);
    m_CountLabel->setText(QString("currnt value %1").arg(m_count));

    m_incrementBtn = new QPushButton(this);
    m_incrementBtn->setText(QString("click is add 1"));

// 2. 用布局管理器组织组件（组合模式的体现：QVBoxLayout是容器，管理子组件）
    QWidget *centralWidget = new QWidget(this); // 主窗口必须有中心部件
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    layout->addWidget(m_CountLabel); // 向布局添加标签
    layout->addWidget(m_incrementBtn); // 向布局添加按钮
    layout->setSpacing(20); // 设置组件间距
    layout->setContentsMargins(50, 50, 50, 50); // 设置布局边距
    // 3. 将中心部件设置给主窗口
    setCentralWidget(centralWidget);
    setWindowTitle("Qt 计数器示例"); // 设置窗口标题
    resize(300, 200); // 设置窗口大小

    // 4. 连接信号与槽（Qt事件驱动的核心）
        // 格式：connect(信号发送者, 信号, 信号接收者, 槽函数)
    connect(m_incrementBtn, &QPushButton::clicked,
        this, &MainWindow::OnIncrementClicked);

}
//// 槽函数实现：按钮点击后执行的逻辑
//void MainWindow::OnIncrementClicked()
//{
//    m_count++; // 业务数据更新
//    // 更新界面组件：数据变化后同步到标签
//    m_CountLabel->setText(QString("当前计数：%1").arg(m_count));
//}

