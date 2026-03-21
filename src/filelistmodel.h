#ifndef FILELISTMODEL_H
#define FILELISTMODEL_H

#include <QAbstractListModel>

// Dosya verilerimizi tutacak yapı
struct FileItem {
    QString fileName;
    QString filePath;
    bool isDir;
};

class FileListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    // QML tarafında erişeceğimiz roller
    enum FileRoles {
        FileNameRole = Qt::UserRole + 1,
        FilePathRole,
        IsDirRole
    };

    explicit FileListModel(QObject *parent = nullptr);

    // QAbstractListModel'in ezilmesi (override) gereken temel fonksiyonları
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    // Arayüzden tetiklenecek tarama fonksiyonu
    Q_INVOKABLE void scanDirectory(const QString &path);

private:
    std::vector<FileItem> m_files;
};

#endif // FILELISTMODEL_H
