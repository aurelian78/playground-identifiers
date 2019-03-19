#include "productid.h"

QDebug operator<<(QDebug debug, const ProductId& productId)
{
    QDebugStateSaver saver(debug);
    debug.nospace();
    debug << "ProductId" << '(';
    if (productId.isNull())
        debug.noquote() << "null";
    else
        debug << productId.value();
    debug << ')';
    return debug;
}

ProductId ProductId::fromString(const QString& s)
{
    if (s.isEmpty())
        return ProductId();

    bool ok;
    int v = s.toInt(&ok);
    return ok ? ProductId(v) : ProductId();
}

uint qHash(const ProductId& id)
{
    return qHash(id.value());
}
