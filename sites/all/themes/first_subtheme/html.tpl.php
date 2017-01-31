<!DOCTYPE html>
<html lang="<?php print $language->language; ?>">
<head profile="<?php print $grddl_profile; ?>">
    <?php print $head; ?>
    <title><?php print $head_title; ?></title>
    <?php print $styles; ?>
    <?php print $scripts; ?>
</head>
<body class="<?php print $classes; ?>" <?php print $attributes; ?>>
    <div id="skip-link">
        <a href="#main-content"><?php print t('Skip to main content'); ?></a>
    </div>
    <?php print $page_top; ?>
    <i><?php print "(html.tpl.php)The secret word (from theme) is: $theme_secret_word" ?></i><br>
    <i><?php print "(html.tpl.php)The secret word (from module) is: $module_secret_word" ?></i><br>
    <?php print $page; ?>
    <?php print $page_bottom; ?>
</body>
</html>