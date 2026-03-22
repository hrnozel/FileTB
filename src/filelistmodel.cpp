#include "filelistmodel.h"
#include <QDirIterator>
#include <QFileInfo>
#include <QUrl>

FileListModel::FileListModel(QObject *parent) : QAbstractListModel(parent) {}

int FileListModel::rowCount(const QModelIndex &parent) const {
    if (parent.isValid()) return 0;
    return static_cast<int>(m_files.size());
}

QVariant FileListModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid() || index.row() >= static_cast<int>(m_files.size()))
        return QVariant();

    const FileItem &item = m_files[index.row()];

    switch (role) {
    case FileNameRole: return item.fileName;
    case FilePathRole: return item.filePath;
    case IsDirRole:    return item.isDir;
    default:           return QVariant();
    }
}

QHash<int, QByteArray> FileListModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[FileNameRole] = "fileName";
    roles[FilePathRole] = "filePath";
    roles[IsDirRole]    = "isDir";
    return roles;
}

void FileListModel::scanDirectory(const QString &path) {
    qDebug() << path;
    beginResetModel();
    m_files.clear();

    QUrl url {path};
    auto locaFile = url.toLocalFile();

    if(QFile::exists(locaFile)) {

        QDirIterator it(locaFile, QDir::Files | QDir::NoDotAndDotDot, QDirIterator::Subdirectories);

        while (it.hasNext()) {
            it.next();
            QFileInfo info = it.fileInfo();

            m_files.push_back({info.fileName(), info.absoluteFilePath(), info.isDir()});
        }
    } else {
        qDebug() << " There is no such a path: " << locaFile;
    }


    endResetModel();
}
