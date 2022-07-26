#include "tweclock.h"
#include "tweclockplugin.h"

#include <QtPlugin>

TweClockPlugin::TweClockPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void TweClockPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool TweClockPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *TweClockPlugin::createWidget(QWidget *parent)
{
    return new TweClock(parent);
}

QString TweClockPlugin::name() const
{
    return QLatin1String("TweClock");
}

QString TweClockPlugin::group() const
{
    return QLatin1String("My Clock");
}

QIcon TweClockPlugin::icon() const
{
    return QIcon(QLatin1String(":/2824441_time_stopwatch_clock_timer.png"));
}

QString TweClockPlugin::toolTip() const
{
    return QLatin1String("");
}

QString TweClockPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool TweClockPlugin::isContainer() const
{
    return false;
}

QString TweClockPlugin::domXml() const
{
    return QLatin1String("<widget class=\"TweClock\" name=\"tweClock\">\n</widget>\n");
}

QString TweClockPlugin::includeFile() const
{
    return QLatin1String("tweclock.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(tweclockplugin, TweClockPlugin)
#endif // QT_VERSION < 0x050000
