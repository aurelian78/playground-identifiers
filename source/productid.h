#ifndef PRODUCTID_H
#define PRODUCTID_H

#include <QtCore/QtDebug>
#include <QtCore/QString>
#include <QtCore/QVariant>

class ProductId
{
public:
    ProductId()
        : m_value(0)
        {}
    explicit ProductId(int value)
        : m_value(value)
        {}

    bool isNull() const
        { return (m_value == 0); }

    int value() const
        { return m_value; }

    bool operator==(const ProductId& other) const
        { return m_value == other.m_value; }
    bool operator!=(const ProductId& other) const
        { return m_value != other.m_value; }

    public:
    QString toString() const
        { return isNull() ? QString() : QString::number(m_value); }
    static ProductId fromString(const QString& s);

private:
    int m_value;
};

QDebug operator<<(QDebug debug, const ProductId& productId);

Q_DECLARE_METATYPE(ProductId)

uint qHash(const ProductId& id);

#endif
