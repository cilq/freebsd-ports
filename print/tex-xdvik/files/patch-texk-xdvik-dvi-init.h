--- texk/xdvik/dvi-init.h.orig	2014-09-02 18:41:34.000000000 +0900
+++ texk/xdvik/dvi-init.h	2015-01-31 21:02:18.000000000 +0900
@@ -100,6 +100,12 @@
     char *pixmap2_gc2;	    /* separate image data for drawing image to globals.gc.fore2 */
 #endif /* GREY */
     struct bitmap bitmap2;  /* shrunken bitmap for character */
+#ifdef PTEX
+    int     tdir;
+#endif /* PTEX */
+    short x3, y3;		/* x and y offset in pixels (backup) */
+    struct bitmap bitmap3;	/* bitmap for character (backup) */
+    float matrix[2][2];
 };
 
 /*
@@ -131,6 +137,9 @@
 #define	FONT_IN_USE	1	/* used for housekeeping */
 #define	FONT_LOADED	2	/* if font file has been read */
 #define	FONT_VIRTUAL	4	/* if font is virtual */
+#ifdef PTEX
+#define	FONT_KANJI	8	/* if font is kanji */
+#endif
 
 /* forward declarations */
 struct font;
@@ -156,6 +165,11 @@
     struct glyph *glyph;
     /* these fields are used by (loaded) virtual fonts */
     struct font **vf_table;	/* list of fonts used by this vf */
+#ifdef PTEX
+    struct glyph **kglyph;
+    int ft2_index;
+    int dir;
+#endif /* PTEX */
     struct tn *vf_chain;	/* ditto, if TeXnumber >= VFTABLELEN */
     struct font *first_font;	/* first font defined */
     struct macro *macro;
@@ -175,6 +189,7 @@
 };
 
 
+extern void free_bitmap2(struct glyph *g);
 extern void reset_fonts(void);
 #if COLOR
 extern void reset_colors(void);
