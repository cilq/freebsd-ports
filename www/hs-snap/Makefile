# $FreeBSD$

PORTNAME=	snap
PORTVERSION=	0.13.2.8
PORTREVISION=	1
CATEGORIES=	www haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	Top-level package for the Snap Web Framework

LICENSE=	BSD3CLAUSE

USE_CABAL=	aeson attoparsec>=0.10 cereal>=0.3 clientsession>=0.8 \
		comonad>=1.1 configurator>=0.1 directory-tree>=0.11 \
		directory-tree>=0.10 dlist>=0.5 errors>=1.4 hashable \
		heist>=0.13 lens>=3.7.6 logict>=0.4.2 MonadCatchIO-transformers>=0.2 \
		mtl>2.0 mwc-random>=0.8 pwstore-fast>=2.2 regex-posix>=0.95 \
		snap-core>=0.9 snap-server>=0.9 stm>=2.2 syb>=0.1 \
		text>=0.11 unordered-containers>=0.1.4 vector>=0.7.1 \
		vector-algorithms>=0.4 xmlhtml>=0.1

EXECUTABLE=	snap

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"
.include <bsd.port.mk>
