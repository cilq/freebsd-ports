# Created by: Zastupov Stepan [RedChrom] <redchrom@mail.ru>
# $FreeBSD$

PORTNAME=	audacious
PORTVERSION=	3.5.2
CATEGORIES=	multimedia audio
MASTER_SITES=	http://distfiles.audacious-media-player.org/

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Media player based on BMP and XMMS

LICENSE=	GPLv3

LIB_DEPENDS=	libmcs.so:${PORTSDIR}/devel/libmcs \
		libmowgli.so:${PORTSDIR}/devel/libmowgli

GNU_CONFIGURE=	yes
USES=		pkgconfig gmake tar:bzip2 desktop-file-utils gettext-tools
USE_XORG=	x11 sm
USE_GNOME=	gtk30 libxml2
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ARGS=	--disable-chardet --with-pkgconfigdir=${PREFIX}/libdata/pkgconfig

OPTIONS_DEFINE=	DBUS ICONV NLS EXECINFO SSE2
OPTIONS_DEFAULT=DBUS ICONV NLS EXECINFO SSE2
EXECINFO_DESC=	Build with libexecinfo support
SSE2_DESC=	Build with SSE2 instruction set

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDBUS}
LIB_DEPENDS+=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
CONFIGURE_ARGS+=--enable-dbus
PLIST_SUB+=	WITH_DBUS=""
.else
CONFIGURE_ARGS+=--disable-dbus
PLIST_SUB+=	WITH_DBUS="@comment "
.endif

.if  ${PORT_OPTIONS:MEXECINFO} || exists(${LOCALBASE}/lib/libexecinfo.so)
LIB_DEPENDS+=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo
.endif

.if  ${PORT_OPTIONS:MICONV} || exists(${LOCALBASE}/lib/libiconv.so)
USES+=		iconv
.endif

.if  ${PORT_OPTIONS:MNLS}
USES+=		gettext-runtime
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if  empty(PORT_OPTIONS:MSSE2)
CONFIGURE_ARGS+=--disable-sse2
.endif

post-patch:
	@${REINPLACE_CMD} 's|$${libdir}/pkgconfig|$${prefix}/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile
.if  ${PORT_OPTIONS:MEXECINFO} || exists(${LOCALBASE}/lib/libexecinfo.so)
	@${REINPLACE_CMD} 's|$${REGEX_LIBS}|& -L${LOCALBASE}/lib -lexecinfo|' \
		${WRKSRC}/src/audacious/Makefile
	@${REINPLACE_CMD} 's|-laudcore|-laudcore -L${LOCALBASE}/lib -lexecinfo|' \
		${WRKSRC}/audacious.pc.in
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/audacious
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libaudcore.so.2.0.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libaudgui.so.2.0.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libaudtag.so.1.0.0
.if ${PORT_OPTIONS:MDBUS}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/audtool
.endif

.include <bsd.port.mk>
