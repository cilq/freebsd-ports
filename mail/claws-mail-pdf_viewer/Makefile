# Created by: Pawel Pekala <c0rn@o2.pl>
# $FreeBSD$

PORTNAME=	pdf_viewer
PORTREVISION=	2

COMMENT=	PDF and PostScript viewer plugin for Claws Mail

LIB_DEPENDS=	libpoppler-glib.so:${PORTSDIR}/graphics/poppler-glib

USE_GHOSTSCRIPT=yes

CLAWS_PLUGINS_BUILD=	pdf_viewer

.include "../claws-mail/Makefile.claws"
.include <bsd.port.mk>
