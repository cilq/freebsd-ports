# Created by: jaapb@kerguelen.org
# $FreeBSD$

PORTNAME=	lwt
PORTVERSION=	2.4.8
PORTREVISION=	2
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Cooperative threading library for OCaml

USE_GITHUB=	yes
GH_ACCOUNT=	ocsigen

LICENSE=	LGPL21

BUILD_DEPENDS=		${SA_DIR}/react/react.a:${PORTSDIR}/devel/ocaml-react \
			${SA_DIR}/ssl/ssl.a:${PORTSDIR}/security/ocaml-ssl
RUN_DEPENDS=		${SA_DIR}/react/react.a:${PORTSDIR}/devel/ocaml-react \
			${SA_DIR}/ssl/ssl.a:${PORTSDIR}/security/ocaml-ssl

MAKE_JOBS_UNSAFE=	yes

USES=			gmake
USE_OCAML=		yes
OCAMLC_DEPEND=		ocaml>=3.11:${OCAMLC_PORT}
USE_OCAML_FINDLIB=	yes
USE_OCAML_CAMLP4=	yes
USE_OCAMLFIND_PLIST=	yes
USE_OCAML_LDCONFIG=	yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		--destdir "${STAGEDIR}" \
			--prefix "${PREFIX}" \
			--enable-camlp4 \
			--enable-ssl \
			--enable-react \
			--disable-libev \
			--disable-glib

DOCSDIR=		${PREFIX}/share/doc/ocaml/${PORTNAME}
SA_DIR=         	${PREFIX}/${OCAML_SITELIBDIR}

OPTIONS_DEFINE=		DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=	--enable-docs --docdir ${STAGEDIR}${DOCSDIR}
# For some reason, ocaml-text is needed when building documentation
BUILD_DEPENDS+=		${SA_DIR}/text/text.a:${PORTSDIR}/textproc/ocaml-text
RUN_DEPENDS+=		${SA_DIR}/text/text.a:${PORTSDIR}/textproc/ocaml-text
.else
CONFIGURE_ARGS+=	--disable-docs
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,"install" :: findlib_name,"install" :: "-destdir ${STAGEDIR}${PREFIX}/lib/ocaml/site-lib" :: "-ldconf /dev/null" :: findlib_name,' \
		${WRKSRC}/setup.ml

do-configure:
	cd ${WRKSRC}; ocaml setup.ml -configure ${CONFIGURE_ARGS}
	@${REINPLACE_CMD} -e 's%"-lev"%"-lev -L${PREFIX}/lib/ev -Wl,-R${PREFIX}/lib/ev"%' \
		${WRKSRC}/setup.data

do-build:
	cd ${WRKSRC}; ocaml setup.ml -build

do-install:
	${MKDIR} ${STAGEDIR}${SA_DIR}
	cd ${WRKSRC}; ocaml setup.ml -install

.include <bsd.port.mk>
