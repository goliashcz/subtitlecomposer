#ifndef COMMONDEFS_H
#define COMMONDEFS_H

/**
 * Copyright (C) 2007-2009 Sergio Pistone <sergio_pistone@yahoo.com.ar>
 * Copyright (C) 2010-2015 Mladen Milinkovic <max@smoothware.net>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include <QString>
#include <QStringList>

#include <QUrl>

class String
{
public:
	static QString title(const QString &text);
	static QString capitalize(const QString &text);
	static QString sentence(const QString &text);

protected:
	static int rfindFunctionStart(const QString &text);
	static int rfindFunctionEnd(const QString &text, int startPos);
};

class System
{
public:
	// returns false on error
	static bool copy(const QString &srcPath, const QString &dstPath);
	static bool move(const QString &srcPath, const QString &dstPath);
	static bool remove(const QString &path);
	static bool recursiveMakeDir(const QString &path, QStringList *createdDirsList = 0);

	static bool isReadable(const QString &path);
	static bool isWritable(const QString &path);

	static QString homeDir();
	static QString tempDir();

	static QUrl urlFromPath(const QString &path);

	static QUrl newUrl(const QUrl &baseUrl, const QString &fileName = QStringLiteral("tempfile"), const QString &extension = QString(), int retries = 10);

	static bool urlIsInside(const QUrl &url, const QString &path);
	static bool urlIsInside(const QUrl &url, QStringList &path);
};

#endif
