# Created by: Martin Tournoij <carpetsmoker@xs4all.nl>
# $FreeBSD$

PORTNAME=	pcmanfm
PORTVERSION=	1.2.3
CATEGORIES=	x11-fm
MASTER_SITES=	SF/${PORTNAME}/PCManFM%20%2B%20Libfm%20%28tarball%20release%29/PCManFM/

MAINTAINER=	horia@racoviceanu.com
COMMENT=	PCMan File Manager

LICENSE=	GPLv2

LIB_DEPENDS=	libfm-gtk.so:${PORTSDIR}/x11/libfm

USES=		desktop-file-utils gmake pkgconfig gettext-tools libtool \
	autoreconf tar:xz
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 gtk20 intltool intlhack
USE_XORG=	x11

CONFIGURE_ARGS=--with-gtk=2

PORTDOCS=	AUTHORS NEWS

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e '/pcmanfm.conf/ d' ${WRKSRC}/data/Makefile.am

post-configure:
# Replace locales files in right place
	${REINPLACE_CMD} -e 's|[$$][(]DATADIRNAME[)]|share|' \
		${WRKSRC}/po/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/xdg/pcmanfm/default/
	${INSTALL_DATA} ${WRKSRC}/data/pcmanfm.conf \
		${STAGEDIR}${PREFIX}/etc/xdg/pcmanfm/default/pcmanfm.conf.sample
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
