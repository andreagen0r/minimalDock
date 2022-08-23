#include <kddockwidgets/Config.h>
#include <kddockwidgets/Platform_qtquick.h>
#include <kddockwidgets/kddockwidgets/ViewFactory.h>
#include <kddockwidgets/private/DockRegistry.h>
#include <kddockwidgets/views/DockWidget_qtquick.h>

#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[]) {
  QGuiApplication app(argc, argv);

  KDDockWidgets::initFrontend(KDDockWidgets::FrontendType::QtQuick);

  auto flags = KDDockWidgets::Config::self().flags();
  KDDockWidgets::Config::self().setFlags(flags);

  QQmlApplicationEngine appEngine;
  KDDockWidgets::Platform_qtquick::instance()->setQmlEngine(&appEngine);
  appEngine.load((QUrl(u"qrc:/untitled/main.qml"_qs)));

  auto dw1 = new KDDockWidgets::Views::DockWidget_qtquick("Dock #1");

  dw1->setGuestItem(QStringLiteral("qrc:/Guest1.qml"));
  dw1->resize(QSize(800, 800));
  dw1->show();

  auto dw2 = new KDDockWidgets::Views::DockWidget_qtquick("Dock #2");
  dw2->setGuestItem(QStringLiteral("qrc:/Guest2.qml"));
  dw2->resize(QSize(800, 800));
  dw2->show();

  auto dw3 = new KDDockWidgets::Views::DockWidget_qtquick("Dock #3");
  dw3->setGuestItem(QStringLiteral("qrc:/Guest3.qml"));

  dw1->addDockWidgetToContainingWindow(dw3, KDDockWidgets::Location_OnRight);

  // Access the main area we created in QML with DockingArea {}
  auto mainArea =
      KDDockWidgets::DockRegistry::self()->mainDockingAreas().constFirst();
  mainArea->addDockWidget(dw2, KDDockWidgets::Location_OnTop);

  return app.exec();
}
