# Created by: Michael C . Wu <keichii@iteration.net>
# $FreeBSD$

PORTNAME=	auto-tw-l10n
PORTVERSION=	1.14
PORTREVISION=	1
CATEGORIES=	chinese
MASTER_SITES=	LOCAL/sunpoet

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automatic localization for Traditional Chinese locale

NO_BUILD=	yes
USES=		tar:xz

SUB_FILES=	pkg-message

pre-install:
	@${FIND} ${WRKSRC} -name "*.orig" -delete

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/skel/zh_TW.UTF-8/
	${INSTALL_DATA} ${WRKSRC}/* ${STAGEDIR}${PREFIX}/share/skel/zh_TW.UTF-8/

.include <bsd.port.mk>
