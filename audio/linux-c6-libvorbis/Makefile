# Created by: Johannes Meixner <xmj@chaot.net>
# $FreeBSD$

PORTNAME=	libvorbis
PORTVERSION=	1.2.3
PORTREVISION=	1
CATEGORIES=	audio linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Audio compression codec library (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-libvorbis-[0-9]* linux-f10-libvorbis-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	c6
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	libogg

RPMVERSION=	4.el6_2.1
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libvorbis.so.0 usr/lib/libvorbis.so.0.4.3 \
		usr/lib/libvorbisenc.so.2 usr/lib/libvorbisenc.so.2.0.6 \
		usr/lib/libvorbisfile.so.3 usr/lib/libvorbisfile.so.3.3.2
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
