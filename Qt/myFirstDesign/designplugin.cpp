#include "design.h"
#include "designplugin.h"

#include <QtPlugin>

designPlugin::designPlugin(QObject *parent)
    : QObject(parent)
{
    m_initialized = false;
}

void designPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (m_initialized)
        return;

    // Add extension registrations, etc. here

    m_initialized = true;
}

bool designPlugin::isInitialized() const
{
    return m_initialized;
}

QWidget *designPlugin::createWidget(QWidget *parent)
{
    return new design(parent);
}

QString designPlugin::name() const
{
    return QLatin1String("design");
}

QString designPlugin::group() const
{
    return QLatin1String("");
}

QIcon designPlugin::icon() const
{
    return QIcon();
}

QString designPlugin::toolTip() const
{
    return QLatin1String("");
}

QString designPlugin::whatsThis() const
{
    return QLatin1String("");
}

bool designPlugin::isContainer() const
{
    return false;
}

QString designPlugin::domXml() const
{
    return QLatin1String("<widget class=\"design\" name=\"design\">\n</widget>\n");
}

QString designPlugin::includeFile() const
{
    return QLatin1String("design.h");
}
#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(designplugin, designPlugin)
#endif // QT_VERSION < 0x050000
