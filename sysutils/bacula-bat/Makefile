# Created by: Dan Langille <dan@langille.org>
# $FreeBSD$

PORTNAME=	bacula
PORTREVISION=	3
PKGNAMESUFFIX=	-bat

COMMENT=	Network backup solution (GUI)

LIB_DEPENDS+=	libqwt.so:${PORTSDIR}/x11-toolkits/qwt5 \
		libbac.so:${PORTSDIR}/sysutils/bacula-client

USES=		pkgconfig
USE_QT4=	qmake_build uic_build moc_build rcc_build
WITH_BAT=	yes

PLIST=		${.CURDIR}/pkg-plist
MAKE_ENV+=	MAKEOBJDIRPREFIX=/

MASTERDIR=	${.CURDIR}/../../sysutils/bacula-server

CONFIGURE_ARGS+=	--enable-bat \
			--with-qwt=${LOCALBASE}/lib \
			--disable-build-dird \
			--disable-build-stored \
			--enable-client-only

OPTIONS_DEFINE=	#
OPTIONS_DEFAULT=#

.include "${MASTERDIR}/Makefile"
