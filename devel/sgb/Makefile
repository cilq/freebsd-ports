# Created by: Gerald Pfeifer <gerald@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sgb
PORTVERSION=	20090810
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.cs.stanford.edu/pub/sgb/ \
		GENTOO
DISTNAME=	sgb-2009-08-10

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	The Stanford GraphBase: A Platform for Combinatorial Computing

BUILD_DEPENDS=	ctangle:${PORTSDIR}/devel/cweb

NO_WRKSUBDIR=	yes
ALL_TARGET=	lib tests
MAKE_JOBS_UNSAFE=	yes
MAKE_ENV+=	STAGEDIR=${STAGEDIR}

.include <bsd.port.pre.mk>

post-extract:
	${CP} ${WRKSRC}/PROTOTYPES/* ${WRKSRC}

.include <bsd.port.post.mk>
