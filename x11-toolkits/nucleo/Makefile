# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nucleo
PORTVERSION=	0.7.6
PORTREVISION=	12
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://insitu.lri.fr/metisse/download/nucleo/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Toolkit to explore video and human-computer interaction

LICENSE=	LGPL21

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libexif.so:${PORTSDIR}/graphics/libexif \
		libpng.so:${PORTSDIR}/graphics/png \
		libfreetype.so:${PORTSDIR}/print/freetype2

USES=		gmake libtool pathfix pkgconfig shebangfix tar:bzip2
USE_GL=		glu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-opencv
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
SHEBANG_FILES=	docs/MacOSX/nBundle.in

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	FFMPEG GD GNUTLS QT4
OPTIONS_RADIO=	DNSSD
OPTIONS_RADIO_DNSSD=	AVAHI MDNSRESPONDER
OPTIONS_SUB=	yes
DNSSD_DESC=		Service discovery

AVAHI_LIB_DEPENDS=	libdns_sd.so:${PORTSDIR}/net/avahi-libdns
AVAHI_CPPFLAGS=		-I${LOCALBASE}/include/avahi-compat-libdns_sd

FFMPEG_DESC=		Build FFmpeg plugin
FFMPEG_LIB_DEPENDS=	libavformat.so:${PORTSDIR}/multimedia/ffmpeg
FFMPEG_CONFIGURE_OFF=	--without-ffmpeg

GD_DESC=		Build GD plugin
GD_LIB_DEPENDS=		libgd.so:${PORTSDIR}/graphics/gd

QT4_DESC=		Build Qt 4 plugin
GD_CONFIGURE_OFF=	--without-gd

GNUTLS_LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls
GNUTLS_CONFIGURE_OFF=	--without-gnutls

MDNSRESPONDER_LIB_DEPENDS=	libdns_sd.so:${PORTSDIR}/net/mDNSResponder

QT4_USE=		QT4=moc_build,corelib
QT4_CONFIGURE_OFF=	--without-qt
QT4_MAKE_ARGS=		QT4MOC="${MOC}"

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MAVAHI} && ! ${PORT_OPTIONS:MMDNSRESPONDER}
CONFIGURE_ARGS+=	--without-dns-sd
.endif

.if ${PORT_OPTIONS:MQT4}
QT_NONSTANDARD=		yes
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/nucleo

.include <bsd.port.mk>
