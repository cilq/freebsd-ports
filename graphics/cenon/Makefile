# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cenon
PORTVERSION=	4.0.2
PORTREVISION=	2
CATEGORIES=	graphics gnustep
MASTER_SITES=	http://www.vhf-group.com/vhf-interservice/download/source/
DISTNAME=	Cenon-${MAINVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	theraven@FreeBSD.org
COMMENT=	Vector graphics tool for GNUstep

USES=	tar:bzip2 gnustep
USE_GNUSTEP=	back build

WRKSRC=		${WRKDIR}/Cenon
MAINVERSION=	4.0.2
FULLVERSION=	4.0.0
CENON_LIB_DIR=	${GNUSTEP_LOCAL_ROOT}/Library/Cenon

OPTIONS_DEFINE=	FULL_LIBRARY
FULL_LIBRARY_DESC=	Install complete Cenon Library

.include <bsd.port.options.mk>

DISTFILES+=	CenonLibrary-${FULLVERSION}-1${EXTRACT_SUFX}

pre-install:
	${MKDIR} ${STAGEDIR}${GNUSTEP_LOCAL_ROOT}/Library/
	${TAR} -xyvf ${_DISTDIR}/CenonLibrary-${FULLVERSION}-1${EXTRACT_SUFX} \
		-C ${STAGEDIR}${GNUSTEP_LOCAL_ROOT}/Library/ \
		--exclude COPYING --exclude '._*'

.include <bsd.port.mk>
