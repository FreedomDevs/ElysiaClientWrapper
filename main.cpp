#include <QApplication>
#include <QLabel>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QWidget>

class UpdateWindow : public QWidget {
public:
  UpdateWindow() {
    setFixedSize(380, 155);

    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint |
                   Qt::Tool);

    auto *layout = new QVBoxLayout(this);
    layout->setContentsMargins(26, 22, 26, 22);
    layout->setSpacing(0);

    auto *title = new QLabel("<span style='color: #f2f3f5;'>Elysia</span>"
                             "<span style='color: #ff3366;'>Client</span>");

    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("font-size: 19px;"
                         "font-weight: 600;");

    auto *status = new QLabel("Checking for updates...");
    status->setStyleSheet("color: #b5bac1;"
                          "font-size: 13px;"
                          "font-weight: 400;");

    auto *progress = new QProgressBar();
    progress->setRange(0, 100);
    progress->setValue(35);
    progress->setTextVisible(false);
    progress->setFixedHeight(6);

    layout->addWidget(title);
    layout->addSpacing(5);
    layout->addWidget(status);
    layout->addSpacing(18);
    layout->addWidget(progress);

    setStyleSheet("QWidget {"
                  "    background: #1e1f22;"
                  "    border: none;"
                  "    border-radius: 8px;"
                  "}"

                  "QProgressBar {"
                  "    background: #2b2d31;"
                  "    border: none;"
                  "    border-radius: 3px;"
                  "}"

                  "QProgressBar::chunk {"
                  "    background: #ff3366;"
                  "    border-radius: 3px;"
                  "}");
  }
};

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  UpdateWindow window;
  window.show();

  return app.exec();
}
