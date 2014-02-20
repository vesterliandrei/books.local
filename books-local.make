; makefile for books.local

; define core version and drush make compatibility

core = 7.x
api = 2


; modules

projects[autoassignrole][subdir] = contrib
projects[autoassignrole][download][type] = "git"
projects[autoassignrole][download][url] = "http://git.drupal.org/project/autoassignrole.git"
projects[autoassignrole][download][tag] = "7.x-1.0-beta1"

projects[coder][subdir] = contrib
projects[coder][download][type] = "git"
projects[coder][download][url] = "http://git.drupal.org/project/coder.git"
projects[coder][download][tag] = "7.x-2.0"

projects[ctools][subdir] = contrib
projects[ctools][download][type] = "git"
projects[ctools][download][url] = "http://git.drupal.org/project/ctools.git"
projects[ctools][download][tag] = "7.x-1.3"
projects[ctools][patch][] = https://drupal.org/files/1301908-language-contexts-6.patch

projects[diff][subdir] = contrib
projects[diff][download][type] = "git"
projects[diff][download][url] = "http://git.drupal.org/project/diff.git"
projects[diff][download][tag] = "7.x-3.2"

projects[entity][subdir] = contrib
projects[entity][download][type] = "git"
projects[entity][download][url] = "http://git.drupal.org/project/entity.git"
projects[entity][download][tag] = "7.x-1.0"

projects[entityreference][subdir] = contrib
projects[entityreference][download][type] = "git"
projects[entityreference][download][url] = "http://git.drupal.org/project/entityreference.git"
projects[entityreference][download][tag] = "7.x-1.1"

projects[features][subdir] = contrib
projects[features][download][type] = "git"
projects[features][download][url] = "http://git.drupal.org/project/features.git"
projects[features][download][tag] = "7.x-2.0"

projects[features_extra][subdir] = contrib
projects[features_extra][download][type] = "git"
projects[features_extra][download][url] = "http://git.drupal.org/project/features_extra.git"
projects[features_extra][download][tag] = "7.x-1.0-beta1"

projects[favorites][subdir] = contrib
projects[favorites][download][type] = "git"
projects[favorites][download][url] = "http://git.drupal.org/project/favorites.git"
projects[favorites][download][tag] = "7.x-1.0"

projects[field_collection][subdir] = contrib
projects[field_collection][download][type] = "git"
projects[field_collection][download][url] = "http://git.drupal.org/project/field_collection.git"
projects[field_collection][download][tag] = "7.x-1.0-beta5"

projects[i18n][subdir] = contrib
projects[i18n][download][type] = "git"
projects[i18n][download][url] = "http://git.drupal.org/project/i18n.git"
projects[i18n][download][tag] = "7.x-1.10"

projects[ISBN2node][subdir] = contrib
projects[ISBN2node][download][type] = "git"
projects[ISBN2node][download][url] = "http://git.drupal.org/project/ISBN2node.git"
projects[ISBN2node][download][tag] = "7.x-1.3"

projects[jcarousel][subdir] = contrib
projects[jcarousel][download][type] = "git"
projects[jcarousel][download][url] = "http://git.drupal.org/project/jcarousel.git"
projects[jcarousel][download][tag] = "7.x-2.6"

projects[jquery_update][subdir] = contrib
projects[jquery_update][download][type] = "git"
projects[jquery_update][download][url] = "http://git.drupal.org/project/jquery_update.git"
projects[jquery_update][download][tag] = "7.x-2.3"

projects[l10n_update][subdir] = contrib
projects[l10n_update][download][type] = "git"
projects[l10n_update][download][url] = "http://git.drupal.org/project/l10n_update.git"
projects[l10n_update][download][tag] = "7.x-1.0-beta3"

projects[maillog][subdir] = contrib
projects[maillog][download][type] = "git"
projects[maillog][download][url] = "http://git.drupal.org/project/maillog.git"
projects[maillog][download][branch] = "7.x-1.x"

projects[mailsystem][subdir] = contrib
projects[mailsystem][download][type] = "git"
projects[mailsystem][download][url] = "http://git.drupal.org/project/mailsystem.git"
projects[mailsystem][download][branch] = "7.x-2.34"

projects[metatag][subdir] = contrib
projects[metatag][download][type] = "git"
projects[metatag][download][url] = "http://git.drupal.org/project/metatag.git"
projects[metatag][download][tag] = "7.x-1.0-beta7"

projects[mimemail][subdir] = contrib
projects[mimemail][download][type] = "git"
projects[mimemail][download][url] = "http://git.drupal.org/project/mimemail.git"
projects[mimemail][download][tag] = "7.x-1.0-beta1"

projects[nice_menus][subdir] = contrib
projects[nice_menus][download][type] = "git"
projects[nice_menus][download][url] = "http://git.drupal.org/project/nice_menus.git"
projects[nice_menus][download][tag] = "7.x-2.5"

projects[panels][subdir] = contrib
projects[panels][download][type] = "git"
projects[panels][download][url] = "http://git.drupal.org/project/panels.git"
projects[panels][download][tag] = "7.x-3.3"

projects[pathauto][subdir] = contrib
projects[pathauto][download][type] = "git"
projects[pathauto][download][url] = "http://git.drupal.org/project/pathauto.git"
projects[pathauto][download][tag] = "7.x-1.2"

projects[quicktabs][subdir] = contrib
projects[quicktabs][download][type] = "git"
projects[quicktabs][download][url] = "http://git.drupal.org/project/quicktabs.git"
projects[quicktabs][download][tag] = "7.x-3.6"

projects[rate][subdir] = contrib
projects[rate][download][type] = "git"
projects[rate][download][url] = "http://git.drupal.org/project/rate.git"
projects[rate][download][tag] = "7.x-1.7"

projects[rules][subdir] = contrib
projects[rules][download][type] = "git"
projects[rules][download][url] = "http://git.drupal.org/project/rules.git"
projects[rules][download][tag] = "7.x-2.6"

projects[strongarm][subdir] = contrib
projects[strongarm][download][type] = "git"
projects[strongarm][download][url] = "http://git.drupal.org/project/strongarm.git"
projects[strongarm][download][tag] = "7.x-2.0"

projects[token][subdir] = contrib
projects[token][download][type] = "git"
projects[token][download][url] = "http://git.drupal.org/project/token.git"
projects[token][download][tag] = "7.x-1.5"

projects[variable][subdir] = contrib
projects[variable][download][type] = "git"
projects[variable][download][url] = "http://git.drupal.org/project/variable.git"
projects[variable][download][tag] = "7.x-2.3"

projects[views][subdir] = contrib
projects[views][download][type] = "git"
projects[views][download][url] = "http://git.drupal.org/project/views.git"
projects[views][download][tag] = "7.x-3.7"

projects[votingapi][subdir] = contrib
projects[votingapi][download][type] = "git"
projects[votingapi][download][url] = "http://git.drupal.org/project/votingapi.git"
projects[votingapi][download][tag] = "7.x-2.11"

projects[webform][subdir] = contrib
projects[webform][download][type] = "git"
projects[webform][download][url] = "http://git.drupal.org/project/webform.git"
projects[webform][download][tag] = "7.x-3.19"

projects[wysiwyg][subdir] = contrib
projects[wysiwyg][download][type] = "git"
projects[wysiwyg][download][url] = "http://git.drupal.org/project/wysiwyg.git"
projects[wysiwyg][download][tag] = "7.x-2.2"

projects[wysiwyg_filter][subdir] = contrib
projects[wysiwyg_filter][download][type] = "git"
projects[wysiwyg_filter][download][url] = "http://git.drupal.org/project/wysiwyg_filter.git"
projects[wysiwyg_filter][download][tag] = "7.x-1.6-rc2"

; themes

; libraries

libraries[ckeditor][download][type]= "get"
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%203.6.2/ckeditor_3.6.2.zip"
libraries[ckeditor][directory_name] = "ckeditor"
libraries[ckeditor][destination] = "libraries"
