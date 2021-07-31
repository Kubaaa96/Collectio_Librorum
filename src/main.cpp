#include <QApplication>
#include <QPushButton>
#include <fmt/core.h>
#include <spdlog/spdlog.h>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto button = std::make_unique<QPushButton>("Hello world!", nullptr);
    constexpr int height{600};
    constexpr int width{800};
    fmt::print("Wow\n");
    spdlog::info("Spdlog");
    button->resize(width, height);
    button->show();
    return QApplication::exec();
}
